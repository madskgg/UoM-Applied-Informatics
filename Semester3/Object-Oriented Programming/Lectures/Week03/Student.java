import java.util.Scanner;

public class Student {
	
	//Ιδιότητες
	private String name;
	private String id;
	private Course myCourse;
	
	public Student(String aName, String someId) {
		name = aName;
		id = someId;
	}
	
	public Student(String aName) {
		name = aName;
		id = "Not defined yet";
	}
	
	public Student() {
		
		Scanner in = new Scanner(System.in);
		
		System.out.println("Please enter a neme:");
		String aName = in.nextLine();
		System.out.println("Please enter the id:");
		String sId = in.nextLine();
		
		name = aName;
		id = sId;
	}
	
	//Μέθοδοι
	public void printInfo() {
		System.out.println("Name: " + name);
		System.out.println("ID: " + id);
		System.out.println("is enrolled in: ");
		if(myCourse != null)
			System.out.println(myCourse.getTitle());
		else	
			System.out.println("no course for the moment");
	}
	
	public String getName() {
		return name;
	}
	
	public void setId(String someId) {
		id = someId;	
	}
	
	public void setCourse(Course aCourse) {
		myCourse = aCourse;
		myCourse.setStudent(this);
	}
}