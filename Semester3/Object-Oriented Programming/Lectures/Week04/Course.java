import java.util.ArrayList;

public class Course {
	
	private String title;
	private int credits;
	//Αναφορά τύπου student
	//private Student[] enrolledStudents = new Student[10];
	//private int numberOfStudents = 0;
	
	//private ArrayList enrolledStudents = new ArrayList();
	private ArrayList<Student> enrolledStudents = new ArrayList<>();
	private ClassRoom room;
	
	public Course(String title, int credits) {
		this.title = title;
		this.credits = credits;
	}
	
	public void enrollStudent(Student aStudent) {
		if(enrolledStudents.size() < room.getCapacity()) {
			enrolledStudents.add(aStudent);
			System.out.println("Student has been enrolled");
		}
		else
			System.out.println("The room is full. Student has not been enrolled");
	}
	
	public void setRoom(ClassRoom aRoom) {
		room = aRoom;
	}
	
	public void printDetails() {
		System.out.println("Course: " + title);
		System.out.println("Credits: " + credits + " ECTS");
		System.out.println("is being taught in: " + room.getLocation());
		System.out.println("has the following students: ");
	//	for(int i=0; i<numberOfStudents; i++)
	//  	enrolledStudents[i].printInfo();
		
		for(int i=0; i<enrolledStudents.size(); i++) {
			//Student s = (Student) enrolledStudents.get(i);
			//s.printInfo();
			enrolledStudents.get(i).printInfo();;
		}
		
	}
}
