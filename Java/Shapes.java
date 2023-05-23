import java.util.*;

class Shape{
    double Area;
    double Perimeter;
    double Side;

    double getArea(){
        return this.Area;
    }
    double getPerimeter(){
        return this.Perimeter;
    }
    double getSide(){
        return this.Side;
    }
}

class Circle extends Shape{
    double Radius;
    Circle(double r){
        this.Radius = r;
        this.Perimeter = Math.PI*2*this.Radius;
        this.Area = Math.PI*Math.pow(this.Radius, 2);
    }
    
    @Override
    double getArea(){
        return this.Area;
    }
    
    @Override
    double getPerimeter(){
        return this.Perimeter;
    }
    
    @Override
    double getSide(){
        return this.Radius;
    }
}


class Triangle extends Shape{
    Triangle(double s){
        this.Side = s;
        this.Perimeter = 3*Side;
        this.Area = Math.sqrt(3)*Math.pow(Side, 2)/4;
    }
    
    @Override
    double getArea(){
        return this.Area;
    }
    
    @Override
    double getPerimeter(){
        return this.Perimeter;
    }
    
    @Override
    double getSide(){
        return this.Side;
    }
}


class Pentagon extends Shape{
    Pentagon(double s){
        this.Side = s;
        this.Perimeter = 5*Side;
        this.Area = 0.25*Math.sqrt(5*(5+2*Math.sqrt(5)))*Math.pow(Side, 2);
    }
    
    @Override
    double getArea(){
        return this.Area;
    }
    
    @Override
    double getPerimeter(){
        return this.Perimeter;
    }
    
    @Override
    double getSide(){
        return this.Side;
    }
}

public class Shapes{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Circle circle = new Circle(10);
        Triangle triangle = new Triangle(10);
        Pentagon pentagon = new Pentagon(10);
        
        System.out.println("\nDetails for Circle: ");
        System.out.println("Radius: " + circle.getSide() + " units");
        System.out.println("Area: " + circle.getArea() + " units\u00b2");
        System.out.println("Perimeter: " + circle.getPerimeter() + " units");
        
        System.out.println("\nDetails for Triangle: ");
        System.out.println("Side: " + triangle.getSide() + " units");
        System.out.println("Area: " + triangle.getArea() + " units\u00b2");
        System.out.println("Perimeter: " + triangle.getPerimeter() + " units");
        
        System.out.println("\nDetails for Pentagon: ");
        System.out.println("Side: " + pentagon.getSide() + " units");
        System.out.println("Area: " + pentagon.getArea() + " units\u00b2");
        System.out.println("Perimeter: " + pentagon.getPerimeter() + " units");
        
    }
}
