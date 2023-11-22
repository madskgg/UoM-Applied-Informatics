public class Main {

    public static void main(String[] args) {
        
        Dataset ds = new Dataset();

       /*BankAccount ba1 = new BankAccount(1500);
        BankAccount ba2 = new BankAccount(1800);
        BankAccount ba3 = new BankAccount(1100);

        ds.add(ba1);
        ds.add(ba2);
        ds.add(ba3);

        System.out.println("Average is: " + ds.getAverage());
        System.out.println("Maximum is: " + ds.getMaximum().getBalance());
        System.out.println("Minimum is: " + ds.getMinimum().getBalance());*/

       /* Student s1 = new Student(6.8);
        Student s2 = new Student(9.3);
        Student s3 = new Student(7.5);

        ds.add(s1);
        ds.add(s2);
        ds.add(s3);

        System.out.println("Average is: " + ds.getAverage());
        System.out.println("Maximum is: " + ds.getMaximum().getGPA());
        System.out.println("Minimum is: " + ds.getMinimum().getGPA());
         */

       /*Runner r1 = new Runner(7.3);
        Runner r2 = new Runner(10.1);
        Runner r3 = new Runner(8.9);

        ds.add(r1);
        ds.add(r2);
        ds.add(r3);

        System.out.println("Average is: " + ds.getAverage());
        System.out.println("Maximum is: " + ds.getMaximum().getPace());
        System.out.println("Minimum is: " + ds.getMinimum().getPace());
        */

        Student s1 = new Student(6.8);
        Student s2 = new Student(9.3);
        Student s3 = new Student(7.5);

        ds.add(s1);
        ds.add(s2);
        ds.add(s3);

        System.out.println("Average is: " + ds.getAverage());
        System.out.println("Maximum is: " + ds.getMaximum().getMeasure());
        System.out.println("Minimum is: " + ds.getMinimum().getMeasure());

    }
}
