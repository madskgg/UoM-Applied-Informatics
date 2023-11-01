
public class Main {

	public static void main(String[] args) {
		
		Registry doai = new Registry("Applied Informatics");

		Student s1 = new Student("Babis", "ics22038");
		Student s2 = new Student("Soula", "iis21047");
		Student s3 = new Student("Takis", "iis20112");
		
		Course c1 = new Course("Python", 5);
		Course c2 = new Course("Databases", 5);
		
		//Καταχώρηση μαθημάτων στην γραμματεία
		doai.addCourse(c1);
		doai.addCourse(c2);
		
		ClassRoom r1 = new ClassRoom("Amf13", 80);
		ClassRoom r2 = new ClassRoom("Erg234", 34);
		
		c1.setRoom(r2);
		c2.setRoom(r1);
		
		c1.enrollStudent(s1);
		c1.enrollStudent(s2);
		c2.enrollStudent(s3);
		
		//c1.printDetails();
		//c2.printDetails();
		
		doai.printDepartmentInfo();
	}

}
