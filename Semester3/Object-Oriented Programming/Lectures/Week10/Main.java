import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) {
		/*LinkedList<Integer> list = new LinkedList<>();
 
		list.add(5);
		list.add(7);
		list.add(12);
		list.add(10);
		
		for(Integer item: list)
			System.out.println(item.toString());
		
		Iterator<Integer> iter = list.iterator();
		
		while(iter.hasNext())
			System.out.println(iter.next());
		
		HashSet set = new HashSet();
		
		set.add("John");
		set.add("Mary");
		set.add("John");
		set.add("Nick");
		
		Iterator iter = set.iterator();
		
		while(iter.hasNext()) {
			String next = (String)iter.next();
			System.out.println(next);
		}
		
		
		ArrayList<String> names = new ArrayList<>();
		
		names.add("George");
		names.add("Mary");
		names.add("Nick");
		names.add("Mary");
		names.add("George");
		names.add("Bob");
		
		for(String name: names)
			System.out.println(name);
		System.out.println("-----------");
		
		Collection<String> noDuplicates = new HashSet<String>(names);
		
		for(String s: noDuplicates)
			System.out.println(s);
		
		Collection<String> set1 = new HashSet<String>();
		set1.add("A");
		set1.add("B");
		set1.add("C");
		set1.add("D");
		
		Collection<String> set2 = new HashSet<String>();
		set2.add("D");
		set2.add("E");
		set2.add("F");
		
		//check whether set2 is subset set1
		if(set1.containsAll(set2))
			System.out.println("Set2 is a subset of set1");
		else
			System.out.println("Set 2 is NOT a subset of set1");
		
		//find the union of two sets
//		set1.addAll(set2);
//		String title = "Demonstration of union";
//		int n = 15;
//		printDecoration(set1, title, n);
		
		//find the intersection of two sets
//		set1.retainAll(set2);
//		String title = "Demonstration of intersection";
//		int n = 15;
//		printDecoration(set1, title, n);
		
		//find the set difference
		set1.removeAll(set2);
		String title = "Demonstration of difference";
		int n = 15;
		printDecoration(set1, title, n);*/
		
		/*TreeSet<String> treeSet = new TreeSet<>();
		
		treeSet.add("Olga");
		treeSet.add("Nikos");
		treeSet.add("Babis");
		treeSet.add("Takis");
		
		Iterator<String> iter = treeSet.iterator();
		
		while(iter.hasNext())
			System.out.println(iter.next());*/
		
		BankAccountComparator comparator1 = new BankAccountComparator();
		BankAccountComparator2 comparator2 = new BankAccountComparator2();
		
		TreeSet<BankAccount> treeSet = new TreeSet<>(comparator2);
		
		BankAccount ba1 = new BankAccount("XV001", 1500);
		BankAccount ba2 = new BankAccount("AB015", 1800);
		BankAccount ba3 = new BankAccount("ZY035", 1200);
		BankAccount ba4 = new BankAccount("NN111", 900);
		
		treeSet.add(ba1);
		treeSet.add(ba2);
		treeSet.add(ba3);
		treeSet.add(ba4);
		
		Iterator<BankAccount> iter = treeSet.iterator();
		
		while(iter.hasNext()) {
			BankAccount ba = iter.next();
			System.out.println(ba.getCode() + ": " + ba.getBalance());
		}
	}

	/*private static void printDecoration(Collection<String> set1, String title, int n) {
		System.out.println(title);
		for(int i=0; i<n; i++)
			System.out.print("-");
		System.out.println();
		for(String s: set1)
			System.out.println(s);
		for(int i=0; i<n; i++)
			System.out.print("-");
	}
	*/
	
}

/*class BankAccount implements Comparable{
	
	private String code;
	private double balance;
	
	public BankAccount(String code, double balance) {
		this.code = code;
		this.balance = balance;
	}
	
	public String getCode() {
		return code;
	}
	
	public double getBalance() {
		return balance;
	}

	@Override
	public int compareTo(Object arg0) {
		
		BankAccount other = (BankAccount)arg0;
//		if(balance < other.balance)
//			return -1;
//		else if(balance > other.balance)
//			return 1;
//		else
//			return 0;
		return code.compareTo(other.code);
	}
	
}*/

class BankAccount{
	
	private String code;
	private double balance;
	
	public BankAccount(String code, double balance) {
		this.code = code;
		this.balance = balance;
	}
	
	public String getCode() {
		return code;
	}
	
	public double getBalance() {
		return balance;
	}
	
}

class BankAccountComparator implements Comparator<BankAccount> {

	@Override
	public int compare(BankAccount account1, BankAccount account2) {
		
		Double amount1 = new Double(account1.getBalance());
		Double amount2 = new Double(account2.getBalance());
		
		return amount1.compareTo(amount2);
	}
	
}

class BankAccountComparator2 implements Comparator<BankAccount> {

	@Override
	public int compare(BankAccount account1, BankAccount account2) {
		
		String code1 = account1.getCode();
		String code2 = account2.getCode();
		
		return code1.compareTo(code2);
	}
	
}