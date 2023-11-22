import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        
        ArrayList<Student> students = new ArrayList<>();

        // students.add(new Student("Bob", "Informatics"));
        students.add(new GraduateStudent("Mary", "Psychology", "Roberts"));
        students.add(new UnderGradStudent("Helen", "Physics", 3));

        for(Student student : students)
            student.printInfo();

        for(Student student : students)
            student.printType();
    }

}
