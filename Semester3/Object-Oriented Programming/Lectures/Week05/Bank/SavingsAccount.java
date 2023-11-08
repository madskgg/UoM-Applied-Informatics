
public class SavingsAccount extends BankAccount{
	
	private double interestRate;
	
	public SavingsAccount(String aName, double aRate) {
		// Κλήση του κατασκευαστή της υπερκλάσης
		// μεταβιβάζοντας το όρισμα aName
		super(aName);
		interestRate = aRate;
	}
	
	public void addInterest() {
		balance = balance + balance * interestRate;
	}
	
	public void setInterestRate(double amount) {
		interestRate = amount;
	}
	
	// Επικάλυψη μεθόδου - Overriding
	public void printInfo() {
		System.out.println("This is a savings account");
		System.out.println("Name: " + name);
		System.out.println("Balance: " + balance);
		System.out.println("Interest rate: " + interestRate);
	}
}
