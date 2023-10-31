
public class Main {

	public static void main(String[] args) {
		
		/*Δημιουργία αντικειμένου κλάσης Student
		Student s1 = new Student("John", "ics23047");
		
		// Αποστολή μηνύματος printInfo στο s1
		s1.printInfo();
		
		Student s2 = new Student("Mary");
		s2.printInfo();
		
		//Student s3 = new Student();
		//s3.printInfo();
		
		System.out.println("Student s1 name is: " + s1.getName());
		
		s1.setId("ics21047");
		
		s1.printInfo();*/
		
        Student s1 = new Student("John", "ics23047");
		
		Student s2 = new Student("Mary", "iis22012");
		
		Course c1 = new Course("Java", 5);
		
		Course c2 = new Course("Machine Learning", 5);
		
		s1.printInfo();
		
		s1.setCourse(c2);
		
		s2.setCourse(c1);
		
		c1.printCourseDetails();
	}
	
		
}
