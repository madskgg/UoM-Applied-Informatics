import becker.robots.RobotSE;


public abstract class Dancer extends Thread {
	
	protected RobotSE robot;	
	
	public abstract void move();
	
	public void run() {
		
		move();
		move();
		move();
		move();
	
	}

}
