
public class Reservation {
	
	protected int days;

	public Reservation(int days) {
		this.days = days;
	}
	
	public double calculateCharge() {
		return 120 * days;
	}

}
