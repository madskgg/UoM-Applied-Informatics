import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {

		Ship ship1 = new Ship("Copacabana", 100);
		Ship ship2 = new Ship("Zeus", 150);
		Ship ship3 = new Ship("Rhodes", 225);
		Ship ship4 = new Ship("Titan", 130);
		
		ArrayList<Ship> ships = new ArrayList<>();
		ships.add(ship1);
		ships.add(ship2);
		ships.add(ship3);
		ships.add(ship4);
		
		/*
		Bulk bulk1 = new Bulk("CYX250", "Barcelona", 1800);
		Refrigerator refr1 = new Refrigerator("RR123", "Piraeus", 4.7);
		Bulk bulk2 = new Bulk("YYZ2357", "Rotterdam", 2100);

		ship1.addContainer(bulk1);
		ship1.addContainer(refr1);
		ship1.addContainer(bulk2);
		
		System.out.println("Total charge of ship1: " + ship1.calculateTotalCharge());
		new ChargeCalculatorFrame(ship1);
		*/
		
		new ContainerFrame(ships);
		
	}

}
