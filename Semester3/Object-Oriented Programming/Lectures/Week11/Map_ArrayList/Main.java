import java.util.ArrayList;
import java.util.HashMap;


public class Main {

	public static void main(String[] args) {
		
		ArrayList<String> JohnBooks = new ArrayList<String>();
		JohnBooks.add("Catcher in the Rye");
		JohnBooks.add("Asterix");
		
		ArrayList<String> MaryBooks = new ArrayList<String>();
		MaryBooks.add("Nefelim");
		MaryBooks.add("Giati mas psekazoun?");
		
		HashMap<String, ArrayList<String>> map = new HashMap<String, ArrayList<String>>();
		
		map.put("John", JohnBooks);
		map.put("Mary", MaryBooks);
		
		for(String name: map.keySet()) {
			ArrayList<String> borrowedBooks = map.get(name);
			System.out.println(name + " has borrowed the following Books: ");
			for(String bookTitle : borrowedBooks)
				System.out.println(bookTitle);
		}

	}

}
