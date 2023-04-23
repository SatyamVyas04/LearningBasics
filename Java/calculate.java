public class calculate {
    public static void main(String[] args) {
        Test test = new Test();
        test.display(test.calculate(2, 4));
        test.display(test.calculate(2.0, 4));
    }
}

class Test{
    double base;
    int power, logBase, argument;
    Test(){
        this.base = 2.0;
        this.power = 2;
        this.logBase = 2;
        this.argument = 2;
    }

    double calculate (double base, int power){
        return Math.pow(base, power);
    }

    double calculate (int logBase, int argument){
        return Math.log(argument)/Math.log(logBase);
    }

    void display(double res){
        System.out.println("Ans: "+res);
    }
}
