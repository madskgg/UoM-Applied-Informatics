import becker.robots.City;
import becker.robots.Direction;
import becker.robots.RobotSE;

public abstract class Dancer extends Thread {
	
	protected RobotSE robot;
	
	public Dancer(City c, int str, int ave, Direction dir) {  
		  robot = new RobotSE(c, str, ave, dir);
	      
	}
	
	public abstract void move();
	
	public void run() {
		move();
		move();
		move();
		move();
	}
	
}
