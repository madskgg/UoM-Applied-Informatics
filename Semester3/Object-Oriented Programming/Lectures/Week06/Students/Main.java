import java.util.ArrayList;

// import javax.swing.JOptionPane;

public class Main {

	public static void main(String[] args) {
		
		/*Student s1 = new Student("Mary", "ics22047");
		s1.printInfo();
		
		GraduateStudent s2 = new GraduateStudent("John", "mai21050", "Papadopoulos");
		s2.printInfo();
		*/
		
		/*Student s1;
		s1 = new GraduateStudent("John", "mai22050", "Papadopoulos");
		
		s1.printInfo();
		*/
		
		/*Student s1;
		
		Scanner in = new Scanner(System.in);
		System.out.println("What type of student? 1: Student, 2: Graduate");
		int answer = in.nextInt();
		
		if(answer == 1)
			s1 = new Student("John", "ics22057");
		else
			s1 = new GraduateStudent("Mary", "mai20032", "Nikolaou");
		
		// Καθυστερημένη διασύνδεση - late binding
		// Πολυμορφισμός
		s1.printInfo();
		*/
		
		/*
		boolean more = true;
		ArrayList<Student> students = new ArrayList<>();
		
		while(more) {
			
			String type = JOptionPane.showInputDialog("Enter type of student- 1: student, 2: graduate, 3: phd");
			// Μετατρέπουμε το αλφαριθμητικό σε ακέραιο
			int selection = Integer.parseInt(type);
			
			// Εισαγωγή δεδομένων
			String name = JOptionPane.showInputDialog("Enter name");
			String id = JOptionPane.showInputDialog("Enter ID");
			
			String supervisor = null;
			if(selection == 2) 
				supervisor = JOptionPane.showInputDialog("Enter supervisor");
			
			String thesis = null;
			if(selection == 3) {
				thesis = JOptionPane.showInputDialog("Enter thesis");
			}
			
			// Δημιουργία αντικειμένου φοιτητή
			Student s = null;
			if(selection == 1) 
				s = new Student(name, id);
			else if (selection == 2)
				s = new GraduateStudent(name, id, supervisor);
			else if (selection == 3)
				s = new PhDStudent(name, id, thesis);
			
			students.add(s);
			
			//Πολυμορφική κλήση
			s.printInfo();
			
			
			String answer = JOptionPane.showInputDialog("Another student (y/n)");
			if(answer.equals("n"))
				more = false;
		}
		
		for(int i=0; i<students.size(); i++) {
			students.get(i).printInfo();  // Πολυμορφική κλήση
		}
		*/
		
		ArrayList<Student> students = new ArrayList<>();
		DataEntry.ReadData(students);
		
		// Ίδια λειτουργία με την παραπάνω for
		for(Student s: students)
			s.printInfo();
	}

}
