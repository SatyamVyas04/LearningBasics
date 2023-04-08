import java.util.*;
public class primes {
    static int prime(int n){
        if(n==1) return 0;
        for(int i = 2; i<=Math.sqrt(n); i++){
            if (n%i==0){
                return 0;
            }
        }
        return 1;
    }

    public static void main(String[] args){
        try (Scanner s = new Scanner(System.in)) {
            System.out.print("Enter a list of numbers: ");
            String[] arr = s.nextLine().strip().split(",");
            int[] nums = new int[arr.length];
            
            for(int i = 0; i<arr.length; i++){
                nums[i] = Integer.parseInt(arr[i].strip());
            }
            
            System.out.println("Primes: ");
            for(int a: nums){
                if (prime(a)==1){
                    System.out.println(a);
                }
            }
        }catch(ArithmeticException e){
            System.out.println("Arithmetic Error! ");
        }
    }
}
