
public class ThreadB extends Thread {

	public void run() {
		
		for(int i=0; i<100000; i++)
			System.out.println("Thread B is running");
	}
}