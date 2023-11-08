
public class Main {

	public static void main(String[] args) {
		
		Timestamp t1 = new Timestamp(23, 45, 17);
		t1.printTime();
		
		/*t1.hour++;
		  t1.hour++;
		*/
		
		t1.incrementHourByOne();
		t1.incrementHourByOne();
		
		t1.printTime();
	}

}
