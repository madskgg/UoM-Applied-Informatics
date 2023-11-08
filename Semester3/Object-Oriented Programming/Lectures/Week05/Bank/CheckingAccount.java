
public class CheckingAccount extends BankAccount {
	
	private int transactionsCounter = 0;

	public CheckingAccount(String aName) {
		super(aName);
	}
	
	// Επικάλυψη μεθόδου - Overriding
	public void printInfo() {
		System.out.println("This is a checking account");
		System.out.println("Name: " + name);
		System.out.println("Balance: " + balance);
	}
	
	public void deposit(double amount) {
		// Κλήση της μεθόδου deposit της υπερκλάσης
		super.deposit(amount);
		transactionsCounter++;
		if(transactionsCounter > 2)
			balance -= 0.5;
	}
}
