
public class Student {

	private String name;
	private String id;
	
	public Student(String aName, String someId) {
		name = aName;
		id = someId;
	}
	
	public void printInfo() {
		System.out.println("Name: " + name);
		System.out.println("ID: " + id);
	}
}
