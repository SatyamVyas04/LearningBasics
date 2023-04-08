public class string {
    public static void main(String[] args){
        String str = "TesTing 1 2 3";
        System.out.println(str.equals("Testing"));
        System.out.println(str.contains("TesTing"));
        System.out.println(str.length());
        System.out.println(str.charAt(0));
        System.out.println(str.indexOf("T"));
        System.out.println(str.lastIndexOf("T"));;
        System.out.println(str.toUpperCase());
        System.out.println(str.toLowerCase());
        System.out.println(str.endsWith("3"));
        System.out.println(str.repeat(3));
        System.out.println(str.replace("1", "10"));
    }
}
