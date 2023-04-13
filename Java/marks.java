import java.util.*;
class Student {
    private String name;
    private int[] marks;

    public Student(String name, int[] marks) {
        this.name = name;
        this.marks = marks;
    }

    public double getAverageMarks() {
        int sum = 0;
        for (int mark : marks) {
            sum += mark;
        }
        return (double) sum / marks.length;
    }

    public void displayDetails() {
        System.out.println("Name: " + name);
        System.out.println("Marks: " + Arrays.toString(marks));
        System.out.println("Average marks: " + getAverageMarks());
    }
}


public class marks {
    public static void main(String args[]){
        int[] marks = {80, 75, 85, 90, 95};
        Student student = new Student("John Doe", marks);
        student.displayDetails();
    }
}

