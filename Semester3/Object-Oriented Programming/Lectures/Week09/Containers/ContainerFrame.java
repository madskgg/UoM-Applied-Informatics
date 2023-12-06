import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class ContainerFrame extends JFrame {
	
	private JPanel panel = new JPanel();
	private JTextField codeField = new JTextField("code");
	private JTextField destinationField = new JTextField("destination");
	private JTextField weightField = new JTextField("weight");
	private JTextField powerField = new JTextField("power");
	
	private JButton createBulkButton = new JButton("Create Bulk");
	private JButton createRefrButton = new JButton("Create Refrigerator");
	
	private JList shipList = new JList(); // Όψη μιας λίστας - View
	
	private ArrayList<Ship> ships;
	
	public ContainerFrame(ArrayList<Ship> someShips) {
		
		ships = someShips;
		
		DefaultListModel model = new DefaultListModel(); // Μοντέλο - Model
		
		for(Ship ship: ships) {
			String shipName = ship.getName();
			model.addElement(shipName);
		}
		
		shipList.setModel(model); //Σύνδεση όψης - μοντέλου
		
		panel.add(codeField);
		panel.add(destinationField);
		panel.add(weightField);
		panel.add(powerField);
		panel.add(createBulkButton);
		panel.add(createRefrButton);
		panel.add(shipList);
		this.setContentPane(panel);
		
		ButtonListener listener = new ButtonListener();
		createBulkButton.addActionListener(listener);
		createRefrButton.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(200, 200);
		this.setTitle("Charge Calculator");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			
			String code = codeField.getText();
			String destination = destinationField.getText();
			
			String shipName = (String) shipList.getSelectedValue();
			
			Ship selectedShip = null;
			for(Ship ship: ships) {
				if(ship.getName().equals(shipName))
					selectedShip = ship;
			}
			
			Container container;
			if(e.getSource().equals(createBulkButton)) {
				// Πατήθηκε το πλήκτρο create Bulk
				String weightText = weightField.getText();
				double weight = Double.parseDouble(weightText);
				container = new Bulk(code, destination, weight);
			}
			else {
				// Πατήθηκε το πλήκτρο του create Refr
				String powerText = powerField.getText();
				double power = Double.parseDouble(powerText);
				container = new Refrigerator(code, destination, power);
			}
			
			selectedShip.addContainer(container);
			System.out.println("Total charge for " + shipName + " is: " + selectedShip.calculateTotalCharge());
		}
		
	}
}
