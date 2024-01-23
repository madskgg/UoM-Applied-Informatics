import becker.robots.*;

/** Run a chorus line of dancing robots. 
 *
 * @author Byron Weber Becker */
public class DanceHall
{
   public static void main(String[] args)
   {  City stage = new City();
      Dancer[] chorusline = new Dancer[4];
      
      // initialize the array
      chorusline[0] = new LeftDancer(stage, 1, 0, Direction.EAST);
      chorusline[2] = new LeftDancer(stage, 3, 0, Direction.EAST);
      chorusline[1] = new RightDancer(stage, 2, 0, Direction.EAST);
      chorusline[3] = new RightDancer(stage, 4, 0, Direction.EAST);

      for (int i = 0; i < chorusline.length; i++)
      {  
    	  chorusline[i].start();
      }

   }
}

