import java.awt.Color;

import javax.swing.*;

public class MyFrame extends JFrame {
	
	// Βήμα 1ο. Δήλωση και κατασκευή υποδοχέα
	private JPanel panel = new JPanel();
	
	// Βήμα 2ο. Δημιουργία γραφικών συστατικών
	private JTextField textField = new JTextField("Please enter your name");
	private JButton button = new JButton("Press Me");
	private ImageIcon icon;
	private JLabel label;
	
	public MyFrame() {
		
		icon = new ImageIcon("uom.jpg");
		label = new JLabel(icon);
		
		// Βήμα 3ο. Προσθήκη γραφικών συστατικών στον υποδοχέα
		panel.add(textField);
		panel.add(button);
		panel.add(label);
		
		panel.setBackground(Color.RED);
		
		// Βήμα 4ο. Προσαρμογή του panel στο παράθυρο
		this.setContentPane(panel);
	}
}
