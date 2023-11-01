import java.util.ArrayList;

public class Registry {
	private String department;
	
	private ArrayList<Course> courses = new ArrayList<>();
	
	public Registry(String department) {
		this.department = department;
	}
	
	public void addCourse(Course aCourse) {
		courses.add(aCourse);
	}
	
	public void printDepartmentInfo() {
		System.out.println("Department name: " + department);
		for(int i=0; i<courses.size(); i++)
			courses.get(i).printDetails();
	}
}
