
public class Main {

	public static void main(String[] args) {
		
		/*SavingsAccount sa1 = new SavingsAccount();
		
		sa1.setName("Papadopoulos");
		sa1.setBalance(1200); */
		
		BankAccount ba1 = new BankAccount("Ioannou");
		ba1.setBalance(900);
		ba1.printInfo();
		
		SavingsAccount sa1 = new SavingsAccount("Papadopoulos", 0.02);
		
		sa1.setBalance(1200);
		sa1.printInfo();
		
		//sa1.setInterestRate(0.02);
		sa1.addInterest();
		sa1.printInfo();
		
		CheckingAccount ca1 = new CheckingAccount("Nikolaou");
		ca1.setBalance(1500);
		ca1.printInfo();
		
		ca1.deposit(100);
		ca1.deposit(100);
		ca1.deposit(100);
		ca1.printInfo();
	}

}
