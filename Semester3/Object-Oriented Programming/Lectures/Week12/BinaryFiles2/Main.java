import java.io.*;


public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		Employee e = new Employee("John");
		
		try {
			FileOutputStream fileOut = new FileOutputStream("employee.ser");
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(e);
			out.close();
			fileOut.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}

	}

}
