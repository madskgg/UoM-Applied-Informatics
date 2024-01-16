import java.util.ArrayList;

public class CentralRegistry {

    // Δηλώνουμε μεθόδους ως static ώστε να μην χρειάζεται να δημιουργήσουμε κάποιο αντικείμενο
    // της κλάσης CentralRegistry

    private static ArrayList<Airport> airports = new ArrayList<>();
    private static ArrayList<Flight> flights = new ArrayList<>();

    // Προσθήκη πτήσης στο ArrayList flights
    public static void addFlight(Flight aFlight) {
        flights.add(aFlight);

        // Προσθήκη της αντίστοιχης αεροπορικής στο ArrayList airline τόσο για το αρχικό όσο 
        // και το τελικό αεροδρόμιο
        Airport airportA = aFlight.getAirportA();
        Airport airportB = aFlight.getAirportB();

        String airline = aFlight.getAirline();

        if (!airportA.getAirlines().contains(airline)) 
            airportA.addAirline(airline);
        if (!airportB.getAirlines().contains(airline)) 
            airportB.addAirline(airline);
        
    }

    // Προσθήκη αεροδρομίου στο ArrayList airports
    public static void addAirport(Airport anAirport) {
        airports.add(anAirport);
    }

    // Εύρεση μεγαλύτερου αεροδρομίου ανατρέχοντας το ArrayList airports
    public static Airport getLargestHub() {
        Airport largestHub = null;
        int maxDirectConnections = -1;

        for (Airport airport : airports) {
            int directConnections = airport.getDirectFlightAirports().size();
            if (directConnections > maxDirectConnections) {
                maxDirectConnections = directConnections;
                largestHub = airport;
            }
        }

        return largestHub;
    }

    // Εύρεση μεγαλύτερης σε διάρκεια πτήσης ανατρέχοντας το ArrayList flights
    public static Flight getLongestFlight() {
        Flight longestFlight = null;
        int maxDuration = 0;

        for (Flight flight : flights) {
            int duration = flight.getDuration();
            if (duration > maxDuration) {
                maxDuration = duration;
                longestFlight = flight;
            }
        }

        return longestFlight;
    }
    
    // Μέδοθος η οποία να επιστρέφει το αεροδρόμιο που υπάρχει σε μια πόλη ή αλλιως την τιμή null
    public static Airport getAirport(String cityName) {
        for (Airport airport : airports) {
            if (airport.getCity().equals(cityName)) {
                return airport;
            }
        }
        return null; 
    }
    
    // Μέθοδος για εύρεση απευθείας πτήσεων από το αεροδρόμιο a στο αεροδρόμιο b
    public static String getDirectFlightsDetails(Airport airportA, Airport airportB) {
        String directFlights = "";
        int count = 0;

        for (Flight flight : flights) {
            if (flight.getAirportA().equals(airportA) && flight.getAirportB().equals(airportB)) {
            	count++;
                directFlights += "[" + count + "]" + flight.toString() + "\n";
            }
        }

        return directFlights;
    }
    
    // Μέθοδος για εύρεση πόλης πτήσης με ανταπόκριση
    public static String getInDirectFlightsDetails(Airport airportA, Airport airportB) {
        String commonConnections = "";
        int count = 0;
        
        for (Airport airport : airports) {
            if (airportA.isDirectlyConnectedTo(airport) && airportB.isDirectlyConnectedTo(airport)) {
            	count++;
                commonConnections += "[" + count + "]" + airport.getCity() + ". " + airport.getCode() + " airport\n";
            }
        }

        return commonConnections;
    }
}
