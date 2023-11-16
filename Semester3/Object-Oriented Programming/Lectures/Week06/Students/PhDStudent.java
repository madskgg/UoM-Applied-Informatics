
public class PhDStudent extends Student {
	
	private String thesis;

	public PhDStudent(String aName, String someId, String thesis) {
		super(aName, someId);
		this.thesis = thesis;
	}
	
	public void printInfo() {
		super.printInfo();
		System.out.println("Thesis: " + thesis);
	}

}
