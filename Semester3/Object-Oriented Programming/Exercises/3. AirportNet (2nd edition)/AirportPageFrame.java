import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.Border;

public class AirportPageFrame extends JFrame {
	
	// Ιδιότητες
    private Airport airport;
    private JPanel mainPanel, airportInfoPanel, flightSearchPanel, flightDetailPanel, returnPanel;
    private JTextField airportNameTextField, airportCodeTextField, cityNameTextField, countryNameTextField, flightSearchTextField;
    private JList<String> airlineList;
    private JTextArea directFlightsTextField, indirectFlightsTextField;
    private JButton findFlightsButton, backButton;
    private Border gray;
    
    // Constructor
    public AirportPageFrame(Airport airport) {
        this.airport = airport;
        
        // Μέθοδος για την δημιουργία και προσθήκη όλων τον panels στο παράθυρο
        setPanels();
        
        // Καθορισμός βασικών στοιχείων παραθύρου
        setTitle("Airport Page");
		setSize(700,550);
		setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
    
    private void setPanels() {
    	// Main Panel
        mainPanel = new JPanel();
        
        // Airport Info Panel
        airportInfoPanel = new JPanel();
        
        // Πεδία για τις πληροφορίες του αεροδρομίου
        airportNameTextField = new JTextField(airport.getName(), 10);
        airportCodeTextField = new JTextField(airport.getCode(), 10);
        cityNameTextField = new JTextField(airport.getCity(), 10);
        countryNameTextField = new JTextField(airport.getCountry(), 10);
        ArrayList<String> airlinesArrayList = new ArrayList<>(airport.getAirlines());
        
        // Χρήση της βιβλιοθήκης Collections για την ταξινόμηση των αεροπορικών αλφαβητικά
        Collections.sort(airlinesArrayList);
        DefaultListModel<String> model = new DefaultListModel<>();
        for (String airline : airlinesArrayList) {
            model.addElement(airline);
        }
        
        // Δημιουργία JList που περιέχει τις αεροπορικές
        airlineList = new JList<String>(model);
        
        // Ορισμός προτεινούμενου μεγέθους
        airportCodeTextField.setPreferredSize(new Dimension(100, 20));
        airportNameTextField.setPreferredSize(new Dimension(100, 20));
        cityNameTextField.setPreferredSize(new Dimension(100, 20));
        countryNameTextField.setPreferredSize(new Dimension(100, 20));
        airlineList.setPreferredSize(new Dimension(100, 80));

        // Προσθήκη στοιχείων στο panel
        airportInfoPanel.add(airportNameTextField);
        airportInfoPanel.add(airportCodeTextField);
        airportInfoPanel.add(cityNameTextField);
        airportInfoPanel.add(countryNameTextField);
        airportInfoPanel.add(airlineList);
    
        // Flight Search Panel
        flightSearchPanel = new JPanel();
        
        // Πεδίο για τη πόλη προορισμού και κουμπί αναζήτησης αυτού
        flightSearchTextField = new JTextField("Enter a destination city", 15);
        findFlightsButton = new JButton("Find Flights");
        
        // Ορισμός προτεινούμενου μεγέθους
        flightSearchTextField.setPreferredSize(new Dimension(120, 20));

        // Προσθήκη στοιχείων στο panel
        flightSearchPanel.add(flightSearchTextField);
        flightSearchPanel.add(findFlightsButton);
    
        // Flight Detail Panel
        flightDetailPanel = new JPanel();
        
        // Πεδία για τις απευθείας και με ανταπόκριση πτήσεις
        directFlightsTextField = new JTextArea("DIRECT FLIGHT DETAILS\n");
        indirectFlightsTextField = new JTextArea("INDIRECT FLIGHTS through...\n");
        
        // Δημιουργία ενός ActionListener για το κουμπί Find Flights
        findButtonListener listener = new findButtonListener();
        findFlightsButton.addActionListener(listener);
        
        // Ορισμός προτεινούμενου μεγέθους πεδίων και προσθήκη στο panel
        directFlightsTextField.setPreferredSize(new Dimension(300, 200));
        indirectFlightsTextField.setPreferredSize(new Dimension(300, 200));
        
        // Προσθήκη στοιχείων στο panel
        flightDetailPanel.add(directFlightsTextField);
        flightDetailPanel.add(indirectFlightsTextField);

        // Return Panel
        returnPanel = new JPanel();
        
        // Δημιουργία κουμπιού επιστροφής στο αρχικό παράθυρο αναζήτησης και του αντίστοιχου ActionListener
        backButton = new JButton("Back to Search Screen");
        backButtonListener backListener = new backButtonListener();
        backButton.addActionListener(backListener);
        
        //Δημιουργία πλαισίων 
		gray=BorderFactory.createLineBorder(Color.gray,1);
		airportCodeTextField.setBorder(gray);
		airportNameTextField.setBorder(gray);
		cityNameTextField.setBorder(gray);
		countryNameTextField.setBorder(gray);
		flightSearchTextField.setBorder(gray);
		airportInfoPanel.setBorder(gray);
		directFlightsTextField.setBorder(gray);
		indirectFlightsTextField.setBorder(gray);

        // Προσθήκη στοιχείων στο panel
        returnPanel.add(backButton);
        
        // Προσθήκη όλων των panel σε ένα κεντρικό μεγάλο panel
        mainPanel.add(airportInfoPanel);
        mainPanel.add(flightSearchPanel);
        mainPanel.add(flightDetailPanel);
        mainPanel.add(returnPanel);
        
        // Προσθήκη του panel στο παράθυρο
        setContentPane(mainPanel);
    }

    class findButtonListener implements ActionListener {
        
        @Override
        public void actionPerformed(ActionEvent e) {
        	// Αρχικοποίηση μεταβλητών
            Airport airportA = airport;
            String cityDestination = flightSearchTextField.getText();
            Airport airportB = CentralRegistry.getAirport(cityDestination);
            
            // Εμφάνιση μηνύματος λάθους σε περίπτωση εισαγωγής πόλης που δεν υπάρχει και επιστροφή
            if (airportB == null) {
                JOptionPane.showMessageDialog(null, cityDestination + " does not exist", "Message", JOptionPane.WARNING_MESSAGE);	
                return;
            }
            
            // Εμφάνιση μηνύματος σε περίπτωση εισαγωγής ίδιας πόλης και επιστροφή
            if (airportA == airportB) {
                JOptionPane.showMessageDialog(null, "Arrival and departure city cannot be the same!", "Message", JOptionPane.WARNING_MESSAGE);	
                return;
            }
            
            // Χρήση μεθόδων της κλάσης CentralRegistry για την επιστροφή πτήσεων και αεροδρομίων σε δύο μεταβλητές
            String directFlightsText = CentralRegistry.getDirectFlightsDetails(airportA, airportB);
            String indirectFlightsText = CentralRegistry.getInDirectFlightsDetails(airportA, airportB);
            
            // Προσθήκη των παραπάνω στα αντίστοιχα text fields
            directFlightsTextField.setText("DIRECT FLIGHT DETAILS\n" + directFlightsText);
            indirectFlightsTextField.setText("INDIRECT FLIGHTS through...\n" + indirectFlightsText);
        }  
    }
    
    class backButtonListener implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {
            setVisible(false);
            new AirportFindFrame();
        }
    }
}


