
public class Soldier {
	
	private String id;
	private static int counter = 0;
	
	public Soldier(String id) {
		this.id = id;
		counter++;
	}
	
	public static int getCounter() {
		return counter;
	}

}
