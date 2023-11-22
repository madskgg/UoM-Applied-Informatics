public abstract class Student {
    
    private String name;
    private String department;

    public Student(String name, String department) {
        this.name = name;
        this.department = department;
    }

    public void printInfo() {
        System.out.println("Name: " + name);
        System.out.println("Department: " + department);   
    }

    public abstract void printType();

}
