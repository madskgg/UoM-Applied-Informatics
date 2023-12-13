public class Flight {

    // Ιδιότητες
    private Airport airportA;
    private Airport airportB;
    private int duration;
    private String airline;

    // Constructor
    public Flight(Airport airportA, Airport airportB, int duration, String airline) {
        this.airportA = airportA;
        this.airportB = airportB;
        this.duration = duration;
        this.airline = airline;

        airportA.addDirectFlightAirport(airportB);
        airportB.addDirectFlightAirport(airportA);
    }

    // Μέθοδος που επιστρέφει το αρχικό αερόδρομιο της πτήσης
    public Airport getAirportA() {
        return airportA;
    }

    // Μέθοδος που επιστρέφει το αεροδρόμιο προορισμού
    public Airport getAirportB() {
        return airportB;
    }

    // Μέθοδος που επιστρέφει τη διάρκεια της πτήσης
    public int getDuration() {
        return duration;
    }

    // Μέθοδος που επιστρέφει το όνομα της αεροπορικής εταιρίας
    public String getAirline() {
        return airline;
    }
}
