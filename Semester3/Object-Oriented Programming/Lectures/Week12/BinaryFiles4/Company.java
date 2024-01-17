import java.io.Serializable;

public class Company implements Serializable {
	
	private String name;
	
	public Company(String text) {
		name = text;
	}
	
	public String getName() {
		return name;
	}

}
