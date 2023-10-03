/*Να γράψετε πρόγραμμα που λαμβάνει για ένα πλήθος υποθετικών προϊόντων
(για όσα θέλει να καταχωρήσει ο χρήστης), το όνομά τους, την τιμή τους και το
σκορ τους, βάσει κάποιας κλίμακας αξιολόγησης.
Μετά το πέρας της καταχώρησης των στοιχείων το πρόγραμμα εκτυπώνει το
"βέλτιστο" προϊόν, δηλαδή αυτό που επιτυγχάνει τον καλύτερο λόγο σκορ/τιμή.

Παρατήρηση: το πρόγραμμα θα γραφεί στη γλώσσα προγραμματισμού Java, χωρίς ωστόσο να
αξιοποιηθούν οι βασικές αντικειμενοστρεφείς έννοιες, οι οποίες δεν είναι άλλες από τις κλάσεις και τα
αντικείμενα.*/

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {	
	    Scanner keyboard = new Scanner(System.in);
		
		String best_name = "";
		double best_price = 1;
		int best_score = 0;
		
		boolean more = true;
		while(more)
		{
		    String next_name;
		    double next_price;
		    int next_score;
		    
		    System.out.println("Please enter the product name: ");
		    next_name = keyboard.nextLine();
		    System.out.println("Please enter the product price: ");
		    next_price = keyboard.nextDouble();
		    System.out.println("Please enter the product score: ");
		    next_score = keyboard.nextInt();
		    
		    if(next_score/next_price > best_score/best_price) {
		    	best_name = next_name;
		    	best_price = next_price;
		    	best_score = next_score;
		    }
		   
		    System.out.println("Continue? (Yes=1 / No=2)");
		    int answer = keyboard.nextInt();
		    if(answer == 2)
		        more = false;
		    
		    keyboard.nextLine();
		 }
		
		 System.out.println("Best product name: " + best_name + ".");
		 System.out.println("Best product price: " + best_price + " euro.");
		 System.out.println("Best product score: " + best_score + ".");
		 
		 keyboard.close();
	}
}