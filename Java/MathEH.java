import java.util.*;

class ExpressionErrors extends Exception{
    public ExpressionErrors(String Errormsg){
        super(Errormsg);
    }
}

public class MathEH{
    public static void main (String[] args){
        String x;
        String[] arr = new String[3];
        int checkFlag = 0;
        double a, b;
        String operator;
        Scanner sc = new Scanner(System.in);
        
        while(true){
            System.out.println("\nEnter your Expression: ");
            System.out.println("Format: <a><space><operator><space><b>");
            System.out.print(">>> ");
            x = sc.nextLine();
            arr = x.split(" ");
            
            checkFlag = checkA(arr[0], arr[2]);
            if(checkFlag == 0){
                continue;
            }
            System.out.println("> A and B Entered Correctly! ");
            
            checkFlag = checkOpp(arr[1]);
            if(checkFlag == 0){
                continue;
            }
            System.out.println("> Operator Entered Correctly! ");
            System.out.println("> Order appears to be Correct! ");
        }
    }
    public static int checkA(String a, String b){
        try{
            int inta = Integer.parseInt(a);
            int intb = Integer.parseInt(b);
            return 1;
        }
        catch (NumberFormatException n){
            System.out.println(n);
            System.out.println("> A or B are not Numbers!");
            return 0;
        }
    }
    public static int checkOpp(String opp){
        if(opp.equals("+")){
            return 1;
        }else{
            System.out.println("> Invalid Operator Entered!");
            return 0;
        }
        
    }
}
