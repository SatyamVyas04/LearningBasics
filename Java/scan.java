import java.util.*;
public class scan {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            int a = scanner.nextInt();
            System.out.println(a);

            // buffer removal
            scanner.nextLine();

            String str = scanner.nextLine();
            System.out.println(str);

            String[] words = str.split(" ");
            System.out.println(words);

            for (String ret : words) {
                System.out.println(ret);
            }
        }
    }
}
