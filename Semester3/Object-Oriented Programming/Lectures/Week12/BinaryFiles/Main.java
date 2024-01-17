import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;

public class Main {

	public static void main(String[] args) {

		Employee e = new Employee("John");
		
		File file = new File("employees.ser");
		
		try {
			FileOutputStream outStream = new FileOutputStream(file);
			ObjectOutputStream out = new ObjectOutputStream(outStream);
			
			out.writeObject(e); // εγγραφή του αντικειμένου στο δυαδικό αρχείο
			
			System.out.println("Object has been serialized");
			
			out.close();
			outStream.close();
		} catch (FileNotFoundException e1) {
			e1.printStackTrace();
		} catch (IOException e1) {
			e1.printStackTrace();
		}

	}

}
