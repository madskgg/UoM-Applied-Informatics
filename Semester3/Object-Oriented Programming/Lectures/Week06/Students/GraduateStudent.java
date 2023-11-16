
public class GraduateStudent extends Student{
	
	private String supervisor;

	public GraduateStudent(String aName, String someId, String supervisor) {
		super(aName, someId); // Κλήση κατασκευαστή υπερκλάσης
		this.supervisor = supervisor;
	}
	
	// Επικάλυψη μεθόδου
	public void printInfo() {
		super.printInfo();
		System.out.println("Supervisor: " + supervisor);
	}
	

}
