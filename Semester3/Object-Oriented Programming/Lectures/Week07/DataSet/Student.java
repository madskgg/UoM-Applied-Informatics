public class Student implements Measurable {

    private double gpa;

    public Student(double aGPA) {
        gpa = aGPA;
    }
    
    /*
    public double getGPA() {
        return gpa;
    }
    */

    public double getMeasure() {
        return gpa;
    }
}
