import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame {
	
	//Βήμα 1. Δημιουργία υποδοχέα
	private JPanel panel = new JPanel();
	
	//Βήμα 2. Δημιουργία γραφικών συστατικών
	private JTextField nameField = new JTextField("Enter your name");
	private JButton button = new JButton("Greeting");
	private JTextField outputField = new JTextField(20);
	
	public GUI() {
		panel.setBackground(Color.WHITE);
		
		//Βήμα 3. Τοποθέτηση γραφικών συστατικών στον υποδοχέα
		panel.add(nameField);
		panel.add(button);
		panel.add(outputField);
		
		//Βήμα 4. Προσαρμογή panel στο παράθυρο
		this.setContentPane(panel);
		
		//(Χειρισμός συμβάντων). Βήμα 3. Δημιουργία ακροάτη
		ButtonListener listener = new ButtonListener();
		
		//(Χειρισμός συμβάντων). Βήμα 4. Καταχώρηση ακροάτη στην πηγή συμβάντων
		button.addActionListener(listener);
		
		this.setVisible(true);
		this.setSize(400, 400);
		this.setTitle("Basic Event Handling");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	//(Χειρισμός συμβάντων). Βήμα 1ο. Δημιουργία κλάσης ακροατή
	class ButtonListener implements ActionListener {

		//(Χειρισμός συμβάντων). Βήμα 2. Συγγραφή εκτελούμενου κώδικα
		@Override
		public void actionPerformed(ActionEvent arg0) {
			
			String name = nameField.getText();
			
			//System.out.println("Hello my friends " + name);
			outputField.setText("Hello my friends " + name);
		}
		
	}
}
