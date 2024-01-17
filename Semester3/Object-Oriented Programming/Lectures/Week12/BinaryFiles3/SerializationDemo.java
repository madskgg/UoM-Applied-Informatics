import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;


public class SerializationDemo {
	
	private ArrayList<Employee> employees = new ArrayList<Employee>();
	
	public SerializationDemo() {
		employees.add(new Employee("John"));
		employees.add(new Employee("Bob"));
		
		serializing();
		
		ArrayList<Employee> employeesFromFile = deserializing();
		
		for(Employee e: employeesFromFile) {
			System.out.println("Name: " + e.getName());
		}
		
	}
	
	public void serializing() {
		try {
			FileOutputStream fileOut = new FileOutputStream("employee.ser");
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(employees);
			out.close();
			fileOut.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}
		finally {
			System.out.println("Serialization Attempted...");
		}
		
	}
	
	public ArrayList<Employee> deserializing() {
		try {
			FileInputStream fileIn = new FileInputStream("employee.ser");
			ObjectInputStream in = new ObjectInputStream(fileIn);
			ArrayList<Employee> employees = (ArrayList<Employee>) in.readObject();
			in.close();
			fileIn.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}
		catch(ClassNotFoundException c) {
			c.printStackTrace();
		}
		finally {
			System.out.println("De-Serialization Attempted...");
			return employees;
		}
		
	}
	


}
