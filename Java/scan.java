import java.util.*;

public class scan {
    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        System.out.println(a);

        // buffer removal
        scanner.nextLine();

        String str = scanner.nextLine();
        System.out.println(str);

        String[] words = str.split(" ");
        System.out.print(words);
        for (String ret : words) {
            System.out.println(ret);
        }

    }
}
