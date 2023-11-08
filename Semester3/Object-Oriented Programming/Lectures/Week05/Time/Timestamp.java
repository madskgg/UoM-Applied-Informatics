
public class Timestamp {
	
	/* Παραβίαση της αρχής της ενσωμάτωσης
	public int hour;
	public int minute;
	public int second; 
	*/
	
	// Συμμόρφωση με την αρχή της ενσωμάτωσης
	private int hour;
	private int minute;
	private int second; 
	
	public Timestamp(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	
	public void printTime() {
		System.out.println("Time is " + hour + ":" + minute + ":" + second);
	}
	
	public void incrementHourByOne() {
		hour++;
		if(hour == 24)
			hour = 0;
	}

}
