
public class Refrigerator extends Container {
	
	private double power;

	public Refrigerator(String code, String destination, double power) {
		super(code, destination);
		this.power = power;
	}
	
	public double calculateCharge() {
		return power * 2000;
	}

}
