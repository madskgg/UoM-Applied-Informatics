public class Dataset {

    private double sum;
    private int counter;
    /*
    private BankAccount max;
    private BankAccount min;
    private Student max;
    private Student min;
    private Runner max;
    private Runner min;
    */
    private Measurable max;
    private Measurable min;

    public Dataset() {
        sum = 0;
        counter = 0;
        max = null;
        min = null;
    }
    
   /*  public void add(BankAccount item) {
        sum += item.getBalance();
        if(counter == 0 || item.getBalance() > max.getBalance())
            max = item;
        if(counter == 0 || item.getBalance() < min.getBalance())
            min = item;
        counter++;
    }
    */

   /* public void add(Student item) {
        sum += item.getGPA();
        if(counter == 0 || item.getGPA() > max.getGPA())
            max = item;
        if(counter == 0 || item.getGPA() < min.getGPA())
            min = item;
        counter++;
    }*/

    /*  public void add(Runner item) {
        sum += item.getPace();
        if(counter == 0 || item.getPace() > max.getPace())
            max = item;
        if(counter == 0 || item.getPace() < min.getPace())
            min = item;
        counter++;
    }*/

   /* public BankAccount getMaximum() {
        return max;
    }

    public BankAccount getMinimum() {
        return min;
    }
    */

   /* public Student getMaximum() {
        return max;
    }

    public Student getMinimum() {
        return min;
    }
    */

    /*public Runner getMaximum() {
        return max;
    }

    public Runner getMinimum() {
        return min;
    }*/

    public void add(Measurable item) {
        sum += item.getMeasure();
        if(counter == 0 || item.getMeasure() > max.getMeasure())
            max = item;
        if(counter == 0 || item.getMeasure() < min.getMeasure())
            min = item;
        counter++;
    }

    public double getAverage() {
        if(counter == 0)
            return 0;
        return (sum/counter);
    }

    public Measurable getMaximum() {
        return max;
    }

    public Measurable getMinimum() {
        return min;
    }
}
