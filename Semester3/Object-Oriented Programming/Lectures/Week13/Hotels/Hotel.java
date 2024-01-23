import java.io.Serializable;
import java.util.ArrayList;


public class Hotel implements Serializable {
	
	private String name;
	private ArrayList<Reservation> reservations = new ArrayList<>();

	public Hotel(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	public void addReservation(Reservation aReservation) {
		reservations.add(aReservation);
	}
	
	public double calculateTotalCharge() {
		double sum = 0;
		for(Reservation res: reservations)
			sum += res.calculateCharge();
		
		return sum;
	}
}
