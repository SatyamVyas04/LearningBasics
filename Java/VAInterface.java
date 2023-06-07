import java.util.*;

interface Volume{
    double getVolume();
}

interface SurfaceArea{
    double getSurfaceArea();
}

class Cylinder implements Volume, SurfaceArea{
    double Height, Radius;
    
    Cylinder(double r, double h){
        this.Radius = r;
        this.Height = h;
    }
    
    public double getVolume(){
        return Math.PI*Math.pow(Radius, 2)*Height;
    }
    
    public double getSurfaceArea(){
        return 2*(Math.PI*Radius*Height + Math.PI*Math.pow(Radius, 2));
    }
}

public class VAInterface{
    public static void main(String[] args){
        double r, h;
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter the Radius of the Cylinder: ");
        r = sc.nextDouble();
        
        System.out.print("Enter the Height of the Cylinder: ");
        h = sc.nextDouble();

        Cylinder c = new Cylinder(r, h);
        
        System.out.println("Volume of Cylinder = "+c.getVolume() + " Unit\u00B3");
        System.out.println("SurfaceArea of Cylinder = "+c.getSurfaceArea() + " Unit\u00B2");
    }
}
