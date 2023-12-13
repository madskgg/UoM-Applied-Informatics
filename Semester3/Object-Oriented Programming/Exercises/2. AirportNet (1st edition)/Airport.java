import java.util.ArrayList;

public class Airport {

	// Ιδιότητες
    private String name;
    private String code;
    private String city;
    private String country;
    private ArrayList<String> airlines = new ArrayList<>();
    private ArrayList<Airport> directFlightAirports = new ArrayList<>();

    // Constructor
    public Airport(String name, String code, String city, String country) {
        this.name = name;
        this.code = code;
        this.city = city;
        this.country = country;
    }
    
    // Μέθοδος που επιστρέφει μια boolean τιμή ανάλογα με το αν υπάρχει ή όχι
    // ένα συγκεκριμένο αεροδρομίο στο ArrayList directFlightAirports
    public boolean isDirectlyConnectedTo(Airport anAirport) {
        return directFlightAirports.contains(anAirport);
    }

    // Μέθοδος που δέχεται ένα όρισμα Airport, διατρέχει το ArrayList directFlightAirports
    // και για κάθε ενδιάμεσο αεροδρόμιο (inBetweenAirport), ελέγχει αν το anAirport συνδέεται άμεσα 
    // άμεσα με αυτό χρησιμοποιώντας τη μέθοδο isDirectlyConnectedTo και επιστρέφει αντίστοιχα μια boolean τιμή.
    public boolean isInDirectlyConnectedTo(Airport anAirport) {
        for (Airport inBetweenAirport : directFlightAirports) {
            if (anAirport.isDirectlyConnectedTo(inBetweenAirport)) {
                return true;
            }
        }
        return false;
    }


    // Μέθοδος που δημιουργεί ένα ArrayList για την αποθήκευση των κοινών αεροπορικών 
    // συνδέσεων μεταξύ δυο αεροδρομίων και την επιστρέφει.
    public ArrayList<Airport> getCommonConnections(Airport anAirport) {
        ArrayList<Airport> commonConnections = new ArrayList<>();
        for (Airport airport : directFlightAirports) {
            if (anAirport.isDirectlyConnectedTo(airport)) {
                commonConnections.add(airport);
            }
        }
        return commonConnections;
    }

    // Μέθοδος που εκτυπώνει τις επωνυμίες των αεροπορικών
    public void printCompanies() {
        for (String airline : airlines) {
            System.out.println(airline);
        }
    }

    // Μέθοδος που επιστρέφει το όνομα της πόλης
    public String getName() {
        return name;
    }

    // Μέθοδος που επιστρέφει το ArrayList με τις αεροπορικές
    public ArrayList<String> getAirlines() {
        return airlines;
    }

    // Μέθοδος που επιστρέφει το ArrayList με τα αεροδρόμια με απευθείας σύνδεση
    public ArrayList<Airport> getDirectFlightAirports() {
        return directFlightAirports;
    }

    // Μέθοδος που προσθέτει μια αεροπορική στο ArrayList airlines
    public void addAirline(String airline) {
        airlines.add(airline);
    }

    // Μέθοδος που προσθέτει στο ArrayList directFlightAirports για ένα αερόδρομιο 
    // αυτά με τα οποία έχει απευθείας σύνδεση
    public void addDirectFlightAirport(Airport airport) {
        directFlightAirports.add(airport);
    }
}
