import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class EnrollStudentFrame extends JFrame{
	
	private ArrayList<Course> courses = new ArrayList<>();
	
	private JPanel panel = new JPanel();
	private JTextField nameField = new JTextField("Enter name");
	private JTextField idField = new JTextField("Enter id");
	private JTextField courseField = new JTextField("Enter course");
	private JButton enrollButton = new JButton("Enroll Student");
	private JButton printCourseDetailsButton = new JButton("Print course details");
	
	public EnrollStudentFrame() {
		
		courses.add(new Course("Java", 5));
		courses.add(new Course("Python", 3));
		courses.add(new Course("Haskell", 6));
		
		panel.add(nameField);
		panel.add(idField);
		panel.add(courseField);
		panel.add(enrollButton);
		panel.add(printCourseDetailsButton);
		
		this.setContentPane(panel);
		
		ButtonListener enrollListener = new ButtonListener();
		enrollButton.addActionListener(enrollListener);
		
		this.setVisible(true);
		this.setSize(400, 400);
		this.setTitle("Enroll students in courses");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
	}
	
	class ButtonListener implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent arg0) {
			String name = nameField.getText();
			String id = idField.getText();
			
			Student student = new Student(name, id);
			
			String courseTitle = courseField.getText();
			
			Course selectedCourse = null;
			for(Course course: courses) {
				if(courseTitle.equals(course.getTitle()));
					selectedCourse = course;
			}
			
			selectedCourse.enroll(student);
			System.out.println("Student has been created and enrolled");
		
		}
		
	}
}
