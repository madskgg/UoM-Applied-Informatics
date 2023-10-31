
public class Course {
	
	private String title;
	private int credits;
	private Student myStudent;

	public Course(String aTitle, int someCredits) {
		title = aTitle;
		credits = someCredits;
	}
	
	public void printInfo() {
		System.out.println("Course title: " + title);
		System.out.println("Course credits: " + credits);
	}

	public String getTitle() {
		return title;
	}

	public int getCredits() {
		return credits;
	}
	
	public void setStudent(Student aStudent) {
		myStudent = aStudent;
	}
	
	public void printCourseDetails() {
		System.out.println("Course: " + title);
		System.out.println("is attended by: ");
		System.out.println(myStudent.getName());
	}
}
