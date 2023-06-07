import java.util.*;

interface Area{
    double getArea();
}

interface Perimeter{
    double getPerimeter();
}

class Rectangle implements Area, Perimeter{
    double Breadth, Length;
    
    Rectangle(double l, double b){
        this.Length = l;
        this.Breadth = b;
    }
    
    public double getArea(){
        return Length*Breadth;
    }
    
    public double getPerimeter(){
        return 2*(Length + Breadth);
    }
}

public class APInterface{
    public static void main(String[] args){
        double l, b;
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the Length of the Rectangle: ");
        l = sc.nextDouble();
        
        System.out.print("Enter the Breadth of the Rectangle: ");
        b = sc.nextDouble();

        Rectangle c = new Rectangle(l, b);
        
        System.out.println("Area of Rectangle = "+c.getArea() + " Unit\u00B2");
        System.out.println("Perimeter of Rectangle = "+c.getPerimeter() + " Units");
    }
}
