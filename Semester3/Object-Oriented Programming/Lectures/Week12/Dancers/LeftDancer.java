import becker.robots.*;


/** LeftDancers dance to the left as they move forward.
 *
 * @author Byron Weber Becker 
 * modified by Alexander Chatzigeorgiou*/
public class LeftDancer extends Dancer
{	
   public LeftDancer(City c, int str, int ave, Direction dir)
   {  
	  robot = new RobotSE(c, str, ave, dir);
      robot.setLabel("L");
   }
   
   /** Dance to the left. */
   public void move()
   {  robot.turnLeft();
      robot.move();
      robot.turnRight();
      robot.move();
      robot.turnRight();
      robot.move();
      robot.turnLeft();
   }
}
