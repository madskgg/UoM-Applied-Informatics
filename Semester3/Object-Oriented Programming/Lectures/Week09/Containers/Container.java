
public abstract class Container {

	private String code;
	private String destination;
	
	public Container(String code, String destination) {
		this.code = code;
		this.destination = destination;
	}
	
	public abstract double calculateCharge();
}
