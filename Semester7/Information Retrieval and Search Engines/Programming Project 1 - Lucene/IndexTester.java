import java.io.File;
import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.util.Map;

import jodd.json.JsonParser;

import org.apache.lucene.analysis.en.EnglishAnalyzer; // Import το package που περιλαμβάνει τον EnglishAnalyzer
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.index.LeafReader;
import org.apache.lucene.index.Terms;
import org.apache.lucene.index.TermsEnum;
import org.apache.lucene.queryparser.classic.ParseException;
import org.apache.lucene.queryparser.simple.SimpleQueryParser; // Import το package που περιλαμβάνει τον SimpleQueryParser
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TopDocs;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;

public class IndexTester {

	public static void main(String[] args) throws IOException, ParseException {
		
        if (args.length != 3) {
            System.err.println("Incorrect number of arguments! Usage:");
            System.err.println("");
            System.err.println("java IndexTester should_clear_index path_to_data path_to_index ");
            System.err.println("\tif should_clear_index is \"1\", the index will be rebuilt. Otherwise, it will try and use an existing index.");
            System.err.println("\tpath_to_index should point to an empty directory somewhere.");
            System.exit(-1);
        }
		
        String shouldClearIndex = args[0];
		String inputPath = args[1]; 
		String idxDirPath = args[2];
        
		File inputFile = new File(inputPath);
		
        // Δημιουργία αντικειμένου analyzer τύπου EnglishAnalyzer (Ζήτημα 1 - Αντικατάσταση του StandardAnalyzer με τον EnglishAnalyzer)
		EnglishAnalyzer analyzer = new EnglishAnalyzer();
		
		File idxDir = new File(idxDirPath);
	
		Directory dir = FSDirectory.open(idxDir.toPath());
		
        if (shouldClearIndex.compareTo("1") == 0) {
            System.out.println("Rebuilding index...");
        
            IndexWriterConfig idxConfig = new IndexWriterConfig(analyzer);
            idxConfig.setOpenMode(IndexWriterConfig.OpenMode.CREATE);
            IndexWriter idxWriter = new IndexWriter(dir, idxConfig);

            int idx = 0;
            JsonParser jParser = new JsonParser();
            
            for (String line : Files.readAllLines(inputFile.toPath(), StandardCharsets.UTF_8)) {

                if (idx % 10000 == 0) {
                    System.out.println(idx);
                }
                idx++;
                
                Map j = jParser.parse(line);

                // Ευρετηριοποίηση τίτλων και περιλήψεων (Ζήτημα 2)
                String title = (String)j.get("title");
                String ab = (String)j.get("abstract");

                // Δημιουργία Field για το Document
                Field tiField = new Field("title", title, TextField.TYPE_STORED); 
                Field abField = new Field("abstract", ab, TextField.TYPE_STORED);

                Document thisDoc = new Document();
                // Προσθήκη πεδίων για τίτλους και περιλήψεις στο thisDoc Document
                thisDoc.add(tiField);
                thisDoc.add(abField);

                idxWriter.addDocument(thisDoc);

            }

            System.out.println("Done!");

            System.out.println(idx + " documents indexed.");

            idxWriter.close();

        }

		do {
			DirectoryReader reader = DirectoryReader.open(dir);

			IndexSearcher searcher = new IndexSearcher(reader);
            
            // Αντικατάσταση του QueryParser με τον SimpleQueryParser
			SimpleQueryParser qParserT = new SimpleQueryParser(analyzer, "title");
            // QueryParser για τις περιλήψεις 
            SimpleQueryParser qParserA = new SimpleQueryParser(analyzer, "abstract");
		
			System.out.print("Query: ");
			String queryText = System.console().readLine();
		
			if (queryText.compareTo("") != 0) {
		
				Query qT = qParserT.parse(queryText);
                Query qA = qParserA.parse(queryText);

                // Δημιουργία αντικειμένων τύπου TopDocs που "αντιπροσωπέυουν" τα hits που επιστρέφει ο IndexSearcher
				TopDocs resultsT = searcher.search(qT,  10);
                TopDocs resultsA = searcher.search(qA,  10);

                // Εμφάνιση αριθμού συναφών τίτλων και περιλήψεων
				System.out.println("Title: Got " + resultsT.totalHits + "!");
                System.out.println("Abstract: Got " + resultsA.totalHits + "!");

				for (ScoreDoc d : resultsT.scoreDocs) {
					System.out.println(d.doc + "\t" + d.score);
					Document res = reader.document(d.doc);
					System.out.println(res.getField("title").stringValue());
				}
			}
			
		} while (true); 
		
	}

}
