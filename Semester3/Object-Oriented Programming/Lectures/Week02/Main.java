/*Να γράψετε πρόγραμμα που λαμβάνει για ένα πλήθος υποθετικών
προϊόντων (για όσα θέλει να καταχωρήσει ο χρήστης), το όνομά τους,
την τιμή τους και το σκορ τους, βάσει κάποιας κλίμακας αξιολόγησης.
Μετά το πέρας της καταχώρησης των στοιχείων το πρόγραμμα
εκτυπώνει το "βέλτιστο" προϊόν, δηλαδή αυτό που επιτυγχάνει τον
καλύτερο λόγο σκορ/τιμή.*/

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		
		Product best = new Product();
		
		boolean flag = true;
		while(flag) {
			
			Product current = new Product();
			
			current.read();  
			
			if(current.is_better_than(best))
				best = current;
			
			System.out.println("CONTINUE? (1=YES, 2=NO)");
			int answer = in.nextInt();
			if(answer != 1)
				flag = false;
			in.nextLine();      //flushes the input buffer
		}
		
		System.out.println("Best Product: ");
		best.printData();
		
		in.close();
	}

}
