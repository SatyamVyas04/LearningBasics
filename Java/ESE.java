abstract class Quadrilateral{
	private int x1, y1, x2, y2; 
	private int x3, y3, x4, y4;
	private int[][] coords = {{x1, y1}, {x2, y2}, {x3, y3}, {x4, y4}};
	
	Quadrilateral(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		coords[0][0] = x1;
		coords[0][1] = y1;
		coords[1][0] = x2;
		coords[1][1] = y2;
		coords[2][0] = x3;
		coords[2][1] = y3;
		coords[3][0] = x4;
		coords[3][1] = y4;
	}
	void setter(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		coords[0][0] = x1;
		coords[0][1] = y1;
		coords[1][0] = x2;
		coords[1][1] = y2;
		coords[2][0] = x3;
		coords[2][1] = y3;
		coords[3][0] = x4;
		coords[3][1] = y4;
	}
	abstract double getArea();
	void printcoordinates(){
		System.out.println("Coordinates: ");
		for(int i = 0; i<4; i++){
			System.out.print("> (x" + (i+1) + ", y" + (i+1) + ") = ");
			for(int j = 0; j<2; j++){
				System.out.print(coords[i][j] + " ");
			}
			System.out.print("\n");
		}
	}
}

class Trapezoid extends Quadrilateral{
	double a, b, l;
	Trapezoid(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		// Assuming parallel sides to be parallel to x axis
		super(x1, y1, x2, y2, x3, y3, x4, y4);
		this.a = x2-x1;
		this.b = x4-x3;
		this.l = y1-y3;
	}
	
	double getArea(){
		return l*(a+b)/2;
	}
}

class Parallelogram extends Quadrilateral{
	double l, b;
	Parallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		super(x1, y1, x2, y2, x3, y3, x4, y4);
		this.l = x2-x1;
		this.b = y1-y3;
	}
	
	double getArea(){
		return l*b;
	}
}

class Rectangle extends Parallelogram{
	double l, b;
	Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		super(0, 0, 0, 0, 0, 0, 0, 0); //Setting initial values
		if (!(x1==x3 && x2==x4 && y1==y2 && y3==y4)){
			System.out.println(">> Invalid Rectangle");
			this.l = 0;
			this.b = 0;
		}else{
			super.setter(x1, y1, x2, y2, x3, y3, x4, y4);
			this.l = x2-x1;
			this.b = y1-y3;
		}
	}
	
	double getArea(){
		return l*b;
	}
}

class Square extends Rectangle{
	double a;
	Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
		super(0, 0, 0, 0, 0, 0, 0, 0); //setting initial values
		if (!(y1-y3 - (y2-y4) == x2-x1 - (x4-x3))){
			System.out.println(">> Invalid Square");
			this.a = 0;
		}else{
			super.setter(x1, y1, x2, y2, x3, y3, x4, y4);	
			this.a = x2-x1;
		}
	}
	
	double getArea(){
		return a*a;
	}
}

public class ESE{
	public static void main(String[] args){
		Trapezoid t = new Trapezoid(5, 4, 8, 4, 3, 2, 10, 2);
		Parallelogram p = new Parallelogram(3, 7, 5, 7, 7, 2, 9, 2);
		Rectangle r = new Rectangle(0, 4, 7, 4, 0, 0, 7, 0);
		Square s = new Square(1, 5, 5, 5, 1, 1, 5, 1);
		
		System.out.println("\n>>> Trapezium: ");
		t.printcoordinates();
		System.out.println(">> Area of Trapezium is: " + t.getArea());
		
		System.out.println("\n>>> Parallelogram: ");
		p.printcoordinates();
		System.out.println(">> Area of Parallelogram is: " + p.getArea());
		
		System.out.println("\n>>> Rectangle: ");
		r.printcoordinates();
		System.out.println(">> Area of Rectangle is: " + r.getArea());
		
		System.out.println("\n>>> Square: ");
		s.printcoordinates();
		System.out.println(">> Area of Square is: " + s.getArea());

		System.out.println("\nEnd of Program!");
	}
}



