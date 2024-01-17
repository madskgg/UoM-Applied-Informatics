import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class GUI extends JFrame{
	
	private JTextField inputField;
	private JButton addButton;
	private JList list;
	private JButton sortButton;
	private JPanel panel;
	private DefaultListModel model;
	
	public GUI() {
		
		inputField = new JTextField(10);
		addButton = new JButton("Add");
		list = new JList();
		sortButton = new JButton("Sort");
		panel = new JPanel();
		
		model = new DefaultListModel();
		list.setModel(model);
		
		panel.add(inputField);
		panel.add(addButton);
		panel.add(list);
		panel.add(sortButton);
		
		this.setContentPane(panel);
		
		addButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				model.addElement(inputField.getText());
			}
		});
		
		sortButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ArrayList<String> names = Collections.list(model.elements());
				
				Collections.sort(names);
				
				model.clear();
				
				for(String name: names)
					model.addElement(name);
			}
		});
		
		this.setVisible(true);
		this.setSize(500, 500);
	}

}
