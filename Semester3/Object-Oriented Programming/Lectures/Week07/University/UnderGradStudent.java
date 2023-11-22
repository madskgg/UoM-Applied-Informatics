public class UnderGradStudent extends Student {
   
    private int year;

    public UnderGradStudent(String name, String department, int year) {
        super(name, department);
        this.year = year;
    }

    public void printInfo() {
        super.printInfo();
        System.out.println("Year: " + year);
    }

    public void printType() {
        System.out.println("Hello, I am an undergraduate");
    }
}
