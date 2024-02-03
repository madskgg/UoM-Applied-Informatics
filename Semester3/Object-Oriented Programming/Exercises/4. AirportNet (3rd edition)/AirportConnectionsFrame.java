import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.ArrayList;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

import edu.uci.ics.jung.algorithms.layout.CircleLayout;
import edu.uci.ics.jung.graph.SparseGraph;
import edu.uci.ics.jung.algorithms.shortestpath.DistanceStatistics;
import edu.uci.ics.jung.visualization.VisualizationViewer;
import edu.uci.ics.jung.visualization.decorators.ToStringLabeller;

public class AirportConnectionsFrame extends JFrame {
	
	// Ιδιότητες
	private JPanel mainPanel, graphPanel, bottomPanel;
	private JTextField diameterTextField;
	
    public AirportConnectionsFrame(ArrayList<Airport> airports, ArrayList<Flight> flights) {
    	// Δημιουργία του mainPanel με χρήση της κλάσης BoxLayout
    	mainPanel = new JPanel();
    	mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
    	
    	// Δημιουργία αντικειμένου της κλάσης SparseGraph για την αναπαράσταση των συνδέσεων των αεροδρομίων
    	SparseGraph<String, Flight> graph = new SparseGraph<>();
    	
    	// Προσθήκη κορυφών (πόλεις) στο γράφο
        for (Airport airport : airports) {
            graph.addVertex(airport.getCity());
        }
        
        // Προσθήκη ακμών (πτήσεις) στο γράφο που συνδέουν αεροδρόμια/πόλεις
        for (Flight flight : flights) {
            Airport airportA = flight.getAirportA();
            Airport airportB = flight.getAirportB();
            graph.addEdge(flight, airportA.getCity(), airportB.getCity());
        }

        // Oπτικοποίηση με χρήση της βιβλιοθήκης JUNG 
        CircleLayout<String, Flight> layout = new CircleLayout<>(graph);
        VisualizationViewer<String, Flight> vv = new VisualizationViewer<>(layout);
        vv.setPreferredSize(new Dimension(650, 600));
        vv.getRenderContext().setVertexLabelTransformer(new ToStringLabeller<>());       
        
        // Δημιουργία graphPanel και προσθήκη του αντικειμένου vv σε αυτό
        graphPanel = new JPanel();
        graphPanel.add(vv);
        
        // Δημιουργία bottomPanel
        bottomPanel = new JPanel();
        
        // Υπολογισμός και εμφάνιση της διαμέτρου του γράφου στο diameterTextField με τη χρήση της
        // μεθόδου diameter
        double graphDiameter = DistanceStatistics.diameter(graph);
        diameterTextField = new JTextField("Diameter: " + graphDiameter, 65);
        diameterTextField.setEditable(false);
        bottomPanel.add(diameterTextField, BorderLayout.SOUTH);
        
        // Προσθήκη των δύο panel στο κεντρικό panel
        mainPanel.add(graphPanel);
        mainPanel.add(bottomPanel);
        
        // Καθορισμός βασικών στοιχείων παραθύρου
        setContentPane(mainPanel);
        setTitle("City Airport Connections Network");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
    
}
