import java.util.ArrayList;

public class Course {
	
	private String title;
	private int credits;
	private ArrayList<Student> enrolledStudents = new ArrayList<>();
	
	public Course(String title, int credits) {
		this.title = title;
		this.credits = credits;
	}

	public void enroll(Student aStudent) {
		enrolledStudents.add(aStudent);
	}
	
	public void printInfo() {
		System.out.println("Title: " + title);
		System.out.println("Credits: " + credits);
		System.out.println("has the following students");
		for(Student student: enrolledStudents) 
			student.printInfo();
	}
	
	public String getTitle() {
		return title;
	}
}
