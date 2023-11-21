import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;

public class Game {

    // Ιδιότητες
    private int totalWins;
    private int totalLosses;
    private String lastWord;

    // Constructor
    public Game() {
        totalWins = 0;
        totalLosses = 0;
        lastWord = "-";
    }

    // Methods
	public void play(Scanner in) {
        
        // Δημιουργία αντικειμένων κλάσης Random και Dictionary
        Random random = new Random();
        Dictionary dictionary = new Dictionary();

        // Αρχικοποίηση μεταβλητών
        int guessesLeft = 8, correctGuesses = 0, wrongGuesses = 0;
        
        // Δημιουργούμε μια δομή δεδομένων Set (σύνολο) για να αποθηκεύονται τα γράμματα που έχουν δωθεί
        Set<Character> guessedLetters = new HashSet<>();
        
        // Αποθήκευση μυστικής λέξης με τη χρήση της μεθόδου getWord(index) και έλεγχος να μην υπάρξουν 2 ίδιες λέξεις συνεχόμενα
        String secretWord;

        do {
            secretWord = dictionary.getWord(random.nextInt(100));
        } while (secretWord.equals(lastWord));

        lastWord = secretWord;

        // Δημιουργία πίνακα τύπου char ίσο με το μέγεθος της λέξης και γέμισμα με -
        char[] wordArray = new char[secretWord.length()];

        for(int i=0; i<secretWord.length(); i++)
            wordArray[i] = '-';
        
        System.out.println("The random word is now: " + new String(wordArray));
        System.out.println("You have " + guessesLeft + " guesses left.");

        while (guessesLeft > 0) {
            // Προτρεπτικό μήνυμα και εισαγωγή γράμματος από χρήστη
            System.out.print("Your guess: ");
            String guess = in.nextLine().toUpperCase();

            // Έλεγχος αν ο χρήστης έδωσε σωστό input
            if(guess.length() != 1 || !Character.isLetter(guess.charAt(0))) {
                System.out.println("Please, enter a single letter.");
                continue;
            }
            
            // Μετατροπή της εισόδου σε τύπο char και έλεγχος αν το γράμμα έχει ξαναδωθεί
            char letter = guess.charAt(0);
            if (guessedLetters.contains(letter)) {
                System.out.println("You've already guessed the letter " + letter + ". Try a different one.");
                continue;
            }
            
            // Linear Search, για να αναζητήσουμε αν υπάρχει το γράμμα που έδωσε ο χρήστης
            boolean found = false;
            
            for (int i = 0; i<secretWord.length(); i++) {
                if (letter == secretWord.charAt(i)) {
                    wordArray[i] = letter;
                    found = true;
                }
            }
            
            // Προσθέτουμε το γράμμα στο Set (Σύνολο)
            guessedLetters.add(letter);

            /* Έλεγχοι αν βρέθηκε το γράμμα ή αν βρέθηκε το σύνολο των γραμμάτων της λέξης 
               για την εκτύπωση του αντίστοιχου μηνύματος*/
            if (found) {
                System.out.println("The guess is CORRECT!");
                correctGuesses++;
            }
            else {
                System.out.println("There are no " + letter + "'s in the word.");
                guessesLeft--;
                wrongGuesses++;
            }

            if (secretWord.equals(new String(wordArray))) {
                totalWins++;
                System.out.println("Congratulations! You guessed the word: " + secretWord);
                System.out.println("You made " + correctGuesses + " correct guesses and " + wrongGuesses + " wrong guesses.");
                return;
            }
            else {
                System.out.println("The random word is now: " + new String(wordArray));
                System.out.println("You have " + guessesLeft + " guesses left.");
            }
        }

        totalLosses++;
        System.out.println("You don't have more attempts left. The word was: " + secretWord);

    }

    // Getters
    public int getTotalGames(){
        return totalWins+totalLosses;
    }
    
    public int getWins() {
        return totalWins;
    }

    public int getLosses(){
        return totalLosses;
    }

}
