
public class BankAccount {
	
	protected String name;
	protected double balance;
	
	public BankAccount(String aName) {
		name = aName;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public double getBalance() {
		return balance;
	}
	public void setBalance(double balance) {
		this.balance = balance;
	}
	
	public void printInfo() {
		System.out.println("This is a normal bank account without interest");
		System.out.println("Name: " + name);
		System.out.println("Balance: " + balance);
	}
	
	public void deposit(double amount) {
		balance += amount;
	}

}
