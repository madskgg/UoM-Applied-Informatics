import becker.robots.*;


/** RightDancers dance to the right as they move forward.
 *
 * @author Byron Weber Becker 
 * modified by Alexander Chatzigeorgiou */
 
public class RightDancer extends Dancer
{
	
   public RightDancer(City c, int str, int ave, Direction dir)
   {  
	  super(c, str, ave, dir);
      robot.setLabel("R");
   }
   
   /** Dance to the right. */
   public void move()
   {  robot.turnRight();
      robot.move();
      robot.turnLeft();
      robot.move();
      robot.turnLeft();
      robot.move();
      robot.turnRight();
   }
}
