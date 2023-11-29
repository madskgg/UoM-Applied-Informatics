
public class BankAccount {
	
	private String name;
	private double balance;
	private double interest;
	
	public BankAccount(String name, double balance, double interest) {
		this.name = name;
		this.balance = balance;
		this.interest = interest;
	}
	
	public String toString() {
		return (name + ": " + balance);
	}
	
	public boolean equals(Object other) {
			BankAccount otherAccount = (BankAccount)other;
			
			if(this.name.equals(otherAccount.name) && this.balance == otherAccount.balance)	
				return true;
			
			return false;
				
	}
	
	
}
