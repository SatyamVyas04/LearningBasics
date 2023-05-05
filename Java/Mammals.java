import java.util.Scanner;

public class Mammals {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int num;
        System.out.print("Enter the number of Dogs: ");
        num = sc.nextInt();

        Dog[] dogs = new Dog[num]; 

        int i = 1;
        while(i<=num){
            System.out.print("> Enter 0 for Labrador\n  Enter 1 for GermanSheperd: ");
            int choice = sc.nextInt();
            
            String c, name, colour; 
            int n, age, l;
            double wt, h;
            
            switch (choice) {
                case 0:
                    System.out.print("Enter Dog"+i+"'s Name: ");
                    name = sc.nextLine();
                    System.out.print("Enter Dog"+i+"'s Age: ");
                    age = sc.nextInt();
                    System.out.print("Enter Dog"+i+"'s Colour: ");
                    colour = sc.nextLine();
                    System.out.print("Enter Dog"+i+"'s Weight: ");
                    wt = sc.nextDouble();
                    
                    dogs[i] = new Labrador("Animal", 4, name, age, colour, wt);
                    break;
                
                case 1:
                    System.out.print("Enter Dog"+i+"'s Name: ");
                    name = sc.nextLine();
                    System.out.print("Enter Dog"+i+"'s Age: ");
                    age = sc.nextInt();
                    System.out.print("Enter Dog"+i+"'s Height: ");
                    h = sc.nextDouble();
                    System.out.print("Enter Dog"+i+"'s Lifespan: ");
                    l = sc.nextInt();

                    dogs[i] = new GermanSheperd("Animal", 4, name, age, h, l);
                    break;

                default:
                    System.out.println("Incorrect Input! Retry...");
                    i++;
                    break;
            }
            i--;
        }

        Labrador[] labs = new Labrador[Dog.labradorcount];
        GermanSheperd[] germs = new GermanSheperd[Dog.germancount];

        int labsindex = 0, germanindex = 0;
        for(Dog d: dogs){
            if(d.Type == 'l'){
                labs[labsindex] = d;
                labsindex++;
            }else{
                germs[germanindex] = d;
                germanindex++;
            }
        }

        Dog.popularBreed();
        System.out.println("Avg Wt of Labradors: " + Labrador.calculateAvgWeight(labs));
        System.out.println("Avg Ht of Germans: " + GermanSheperd.calculateAvgHeight(germs));
        
        sc.close();
    }
}

class Mammal{
    String Category;
    int numofLegs;
    Mammal(String c, int n){
        this.Category = c;
        this.numofLegs = n;
    }
}

class Dog extends Mammal{
    static int labradorcount = 0;
    static int germancount = 0;
    String Name;
    int Age;
    int expectedspan;
    char Type; // To seperate dogs
    Dog(String c, int n, String name, int age){
        super(c, n);
        this.Name = name;
        this.Age = age;
    }

    int calculateLifeExpectancy(){
        return this.expectedspan;
    }

    static void popularBreed(){
        if(labradorcount>germancount){
            System.out.println("Labradors are more popular!");
        }else if (labradorcount<germancount){
            System.out.println("German Sheperds are more popular!");
        }else{
            System.out.println("Labradors and German Sheperds are equally popular!");
        }
    }
}

class Labrador extends Dog{
    String Colour;
    double Weight;
    Labrador(String c, int n, String name, int age, String colour, double wt){
        super(c, n, name, age);
        this.Colour = colour;
        this.Weight = wt;
        this.expectedspan = 12; // Assumed
        this.Type = 'l';
        labradorcount++;
    }

    String Speak(){
        return "WOOF!";
    }

    static double calculateAvgWeight(Labrador[] l){
        double sumwts = 0;
        for(Labrador i:l){
            sumwts += i.Weight;
        }
        return sumwts/Dog.labradorcount;
    }
}

class GermanSheperd extends Dog{
    double Height;
    int Lifespan;
    GermanSheperd(String c, int n, String name, int age, double h, int l){
        super(c, n, name, age);
        this.Height = h;
        this.Lifespan = l;
        this.expectedspan = 13; // Assumed
        this.Type = 'g';
        germancount++;
    }

    String Speak(){
        return "GRUNT";
    }

    static double calculateAvgHeight(GermanSheperd[] g){
        double sumhts = 0;
        for(GermanSheperd i:g){
            sumhts += i.Height;
        }
        return sumhts/Dog.germancount;
    }
}