import java.util.*;

class ExpressionErrors extends Exception {
    public ExpressionErrors(String Errormsg) {
        super(Errormsg);
    }
}

public class MathEH {
    public static void main(String[] args) {
        String a, b, o;
        int num1, num2;
        String expression;
        String[] arr = new String[3];
        double Answer;
        Scanner sc = new Scanner(System.in);

        System.out.println("\n---------- Welcome to MathEH Calculator ----------");
        while (true) {
            System.out.println("\nFormat: <a><space><operator><space><b>");
            System.out.print("Enter your Expression: ");
            expression = sc.nextLine();
            arr = expression.split(" ");

            try {
                a = arr[0].strip();
                o = arr[1].strip().toLowerCase();
                b = arr[2].strip();
            } catch (ArrayIndexOutOfBoundsException A) {
                System.out.println("> Error Occured: " + A.getMessage());
                System.out.println("> Invalid Input Format");
                break;
            }

            try {
                numCheck(a);
                num1 = Integer.parseInt(a);
                numCheck(b);
                num2 = Integer.parseInt(b);
                Answer = operatorCheck(num1, o, num2);
                System.out.println(">>> Answer = " + Answer);
            } catch (ExpressionErrors E) {
                System.out.println("> Error Occured: " + E);
            }
            break;
        }
        System.out.println("\n---------------- Thank You ----------------");
    }

    static void numCheck(String x) throws ExpressionErrors {
        try {
            int check = Integer.parseInt(x);
        } catch (NumberFormatException N) {
            throw new ExpressionErrors("\n> A and B are non Integral Values");
        }
    }

    static double operatorCheck(int a, String o, int b) throws ExpressionErrors {
        try {
            switch (o) {
                case "+":
                    return a + b;
                case "-":
                    return a - b;
                case "/":
                    return a / b;
                case "*":
                    return a * b;
                case "log":
                    System.out.println(">>> Assuming A as the Base, ");
                    return Math.log(b) / Math.log(a);
                case "^":
                    return Math.pow(a, b);
                default:
                    throw new ExpressionErrors("\n> Invalid Operator");
            }
        } catch (ArithmeticException A) {
            throw new ExpressionErrors("\n> Zero Division Error");
        }
    }
}
