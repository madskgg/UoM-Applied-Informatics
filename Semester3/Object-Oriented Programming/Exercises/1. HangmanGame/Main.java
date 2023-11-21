import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		// Δημιουργία αντικειμένων της κλάσσης Scanner και Game 
		Scanner in = new Scanner(System.in);
        Game game = new Game();
		
		//Εμφάνιση προτρεπτικού μενού και είσοδος από χρήστη
        while(true) {
        	System.out.println("MAIN MENU");
            System.out.println(" - Start a new Game (N)");
            System.out.println(" - Statistics (S)");
            System.out.println(" - Exit (E)");
            System.out.println("Please enter your choice: ");
            
			// Είσοδος επιλογής από τον χρήστη και έλεγχος των αντίστοιχων περιπτώσεων
            String selection = in.nextLine();
            
            switch(selection) {
            	case "N": 
            		game.play(in);
            		break;
            	case "S":
            		System.out.println("You have played " + game.getTotalGames() + " games so far. You won " + game.getWins() + " times and lost " + game.getLosses() + " times.");
                    break;
            	case "E":
            		in.close();
					System.out.println("Thank you for playing. See you next time!");
            		System.exit(0);
            	default:
            		System.out.println("Wrong Input. Type N, S or E");
            }
        }

	}

}
