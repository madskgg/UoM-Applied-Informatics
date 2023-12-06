import java.awt.event.ActionEvent;

import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class ChargeCalculatorFrame extends JFrame {
	
	private JPanel panel = new JPanel();
	//icon
	private JButton button = new JButton("Calculate total charge");
	private Ship ship;
	
	public ChargeCalculatorFrame(Ship aShip) {
		
		ship = aShip;
		
		panel.add(button);
		this.setContentPane(panel);
		
		ChargeButtonListener chargeListener = new ChargeButtonListener();
		button.addActionListener(chargeListener);
		
		this.setVisible(true);
		this.setSize(200, 200);
		this.setTitle("Charge Calculator");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ChargeButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			
			System.out.println("The total charge is: " + ship.calculateTotalCharge());
			
		}
		
	}
}