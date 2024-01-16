import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class AirportFindFrame extends JFrame {
	
	// Ιδιότητες
    private JPanel panel = new JPanel();
    private JTextField cityNameField = new JTextField("Enter city name", 15);
    private JButton findButton = new JButton("Find");
    
    // Constructor
    public AirportFindFrame() {
    	
    	// Προσθήκη στο panel
    	panel.add(cityNameField);
        panel.add(findButton);
        
        // Προσθήκη στο παράθυρο
        setContentPane(panel);
        
        // Δημιουργία ActionListener για το κουμπί findButton
        ButtonListener listener = new ButtonListener();
        findButton.addActionListener(listener);
		
        // Καθορισμός βασικών στοιχείων παραθύρου
		setVisible(true);
		setSize(300, 150);
		setTitle("Find Airport");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    }
    
    // Υλοποίηση του ActionListener για το κουμπί ButtonListener
    class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			String cityName = cityNameField.getText();
			Airport foundAirport = CentralRegistry.getAirport(cityName);
			
			// Δομή ελέγχου: σε περίπτωση που η πόλη υπάρχει κλείσιμο παραθύρο και δημιουργία νέου παραθύρου AirportPageFrame, αλλιώς
			// εμφάνιση μηνύματος μη ύπαρξης αεροδρομίου στη συγκεκριμένη πόλη
			if (foundAirport != null) {
				setVisible(false);
                new AirportPageFrame(foundAirport);
			}
			else
				JOptionPane.showMessageDialog(null, cityName + " does not have an airport", "Message", JOptionPane.WARNING_MESSAGE);	
		}
		
	}

}
