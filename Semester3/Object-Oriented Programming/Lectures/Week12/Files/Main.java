import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {

		ArrayList<String> names = new ArrayList<>();
		
		names.add("John");
		names.add("Bob");
		names.add("Mary");
		names.add("Susan");
		names.add("Nick");
		names.add("Robert");
		
		try {
			File file = new File("names.txt");
			FileWriter writer = new FileWriter(file);
			
			for(String name: names) {
				writer.write(name);
				writer.write(System.lineSeparator());
			}
			
			writer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
