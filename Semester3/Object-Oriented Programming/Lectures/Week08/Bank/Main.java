
public class Main {

	public static void main(String[] args) {
		
		BankAccount ba1 = new BankAccount("Roberts", 1200, 0.02);
		BankAccount ba2 = new BankAccount("Roberts", 1200, 0.02);
		
		/*
		if(ba1 == ba2)
			System.out.println("The two accounts are identical");
		else
			System.out.println("The two account are different");
		*/
		
		if(ba1.equals(ba2))
			System.out.println("The two accounts are identical");
		else
			System.out.println("The two account are different");
	}

}
