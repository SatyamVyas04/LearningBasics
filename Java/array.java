import java.util.*;
public class array {
    public static void main(String[] args){
        try (Scanner sc = new Scanner(System.in)) {
            ArrayList<String> food = new ArrayList<String>();

            food.add(sc.nextLine());
            food.add(sc.nextLine());
            food.add(sc.nextLine());
            
            // ListIterator<String> it = food.listIterator();

            // while(it.hasNext()){
            //     System.out.println(it.next());
            // }

            System.out.print(food);
            
        }
    }
}
