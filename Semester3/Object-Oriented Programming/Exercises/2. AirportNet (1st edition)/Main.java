import java.util.ArrayList;

public class Main {

	public static void main(String[] args) {
		
		//Creation of airports
		Airport a1 = new Airport("Orly", "ORY", "Paris", "France");
		Airport a2 = new Airport("Fiumicino", "FCO", "Rome", "Italy");
		Airport a3 = new Airport("Venizelos", "ATH", "Athens", "Greece");
		Airport a4 = new Airport("Macedonia", "SKG", "Thessaloniki", "Greece");
		Airport a5 = new Airport("MunichAirport", "MUC", "Munich", "Germany");
		Airport a6 = new Airport("Charleroi", "CRL", "Brussels", "Belgium");
		
		//Creation of flights
		Flight f1 = new Flight(a1, a2, 120, "Air France");
		Flight f2 = new Flight(a1, a5, 90, "Lufthansa");
		Flight f3 = new Flight(a1, a6, 40, "Air France");
		Flight f4 = new Flight(a3, a4, 30, "Aegean");
		Flight f5 = new Flight(a3, a5, 150, "Olympic");
		Flight f6 = new Flight(a4, a5, 120, "Aegean");
		Flight f7 = new Flight(a2, a5, 110, "Alitalia");
		
		
		//Addition to Central Registry
		CentralRegistry.addAirport(a1);
		CentralRegistry.addAirport(a2);
		CentralRegistry.addAirport(a3);
		CentralRegistry.addAirport(a4);
		CentralRegistry.addAirport(a5);
		CentralRegistry.addAirport(a6);
		
		CentralRegistry.addFlight(f1);
		CentralRegistry.addFlight(f2);
		CentralRegistry.addFlight(f3);
		CentralRegistry.addFlight(f4);
		CentralRegistry.addFlight(f5);
		CentralRegistry.addFlight(f6);
		CentralRegistry.addFlight(f7);
		
		//-------------TESTS----------------------
		//Test 1. Largest Hub
		System.out.println("Test 1");
		Airport largestHub = CentralRegistry.getLargestHub();
		System.out.println("Largest Hub: " + largestHub.getName());
		System.out.println();
		
		//Test 2. Longest Flight
		System.out.println("Test 2");
		Flight longestFlight = CentralRegistry.getLongestFlight();
		System.out.println("Longest flight is between: " + longestFlight.getAirportA().getName() + " and " + longestFlight.getAirportB().getName());
		System.out.println();
		
		//Test 3. Check if two airports are directly connected or not
		System.out.println("Test 3");
		if(a1.isDirectlyConnectedTo(a4))
			System.out.println(a1.getName() + " is directly connected to " + a4.getName());
		else
			System.out.println(a1.getName() + " is NOT directly connected to " + a4.getName());
		
		if(a1.isDirectlyConnectedTo(a6))
			System.out.println(a1.getName() + " is directly connected to " + a6.getName());
		else
			System.out.println(a1.getName() + " is NOT directly connected to " + a6.getName());
		System.out.println();
		
		//Test 4. Check if two airports are indirectly connected or not
		System.out.println("Test 4");
		if(a1.isInDirectlyConnectedTo(a4))
			System.out.println(a1.getName() + " is indirectly connected to " + a4.getName());
		else
			System.out.println(a1.getName() + " is NOT directly connected to " + a4.getName());
		
		if(a6.isInDirectlyConnectedTo(a3))
			System.out.println(a6.getName() + " is indirectly connected to " + a3.getName());
		else
			System.out.println(a6.getName() + " is NOT directly connected to " + a3.getName());
		System.out.println();
		
		//Test 5. list common connections
		System.out.println("Test 5");
		System.out.println("Common connections of " + a2.getName() + " and " + a3.getName() + ":");
		ArrayList<Airport> airports = a2.getCommonConnections(a3);
		for(Airport airport: airports)
			System.out.println(airport.getName());
		System.out.println();
		
		//Test 6. Print companies
		System.out.println("Test 6");
		System.out.println("Companies serving " + a3.getName() + ":");
		a3.printCompanies();
		
		System.out.println("Companies serving " + a2.getName() + ":");
		a2.printCompanies();
	}

}
