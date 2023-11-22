public class Runner implements Measurable {
    
    private double pace;

    public Runner(double aPace) {
        pace = aPace;
    }
    
    /*
    public double getPace() {
        return pace;
    }
    */

    public double getMeasure() {
        return pace;
    }

}
