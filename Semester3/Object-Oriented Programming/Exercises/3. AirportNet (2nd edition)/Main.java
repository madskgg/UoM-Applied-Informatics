
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
		Flight f4 = new Flight(a4, a5, 130, "EasyJet");
		Flight f5 = new Flight(a3, a5, 150, "Olympic");
		Flight f6 = new Flight(a4, a5, 120, "Aegean");
		Flight f7 = new Flight(a2, a5, 110, "Alitalia");
		Flight f8 = new Flight(a3, a4, 30, "Aegean");
				
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
		CentralRegistry.addFlight(f8);
		
		//Creation of the "Find Airport" Frame
		new AirportFindFrame();			
	}

}
