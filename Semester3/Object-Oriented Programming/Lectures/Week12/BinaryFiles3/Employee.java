import java.io.Serializable;

public class Employee implements Serializable {
	
	private String name;
	
	public Employee(String text) {
		name = text;
	}
	
	public String getName() {
		return name;
	}

}
