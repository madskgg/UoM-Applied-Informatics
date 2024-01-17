import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class GUI extends JFrame {
	
	private JPanel panel = new JPanel();
	private JButton button = new JButton("Open File");
	private JFileChooser fileChooser = new JFileChooser();
	
	public GUI() {
		
		panel.add(button);
		this.setContentPane(panel);
		
		button.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				int returnVal = fileChooser.showOpenDialog(panel);
				
				if(returnVal == JFileChooser.OPEN_DIALOG) {
					File file = fileChooser.getSelectedFile();
					FileReader fReader;
					try {
						fReader = new FileReader(file);
						BufferedReader reader = new BufferedReader(fReader);
						
						String line = reader.readLine();
						
						while(line != null) {
							System.out.println(line);
							line = reader.readLine();
						}
						
						reader.close();
						fReader.close();
						
						
					} catch (FileNotFoundException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				
			}
			
		});
		
		this.setVisible(true);
		this.setSize(300, 300);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
