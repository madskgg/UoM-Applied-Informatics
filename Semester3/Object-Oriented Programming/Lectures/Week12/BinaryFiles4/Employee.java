import java.io.Serializable;

public class Employee implements Serializable {
	
	private String name;
	private Company company;
	
	public Employee(String text, Company c) {
		name = text;
		company = c;
	}
	
	public void printInfo() {
		System.out.println("Name: " + name + " works for :" + company.getName());
	}

}
