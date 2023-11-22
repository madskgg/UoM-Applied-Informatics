public class GraduateStudent extends Student {
    
    private String supervisor;

    public GraduateStudent(String name, String department, String supervisor) {
        super(name, department);
        this.supervisor = supervisor;
    }

    public void printInfo() {
        super.printInfo();
        System.out.println("Supervisor: " + supervisor);
    }

    public void printType() {
        System.out.println("Hello, I am a postgraduate");
    }
}
