class myRunnable implements Runnable{
    public void run(){
        System.out.println("Test");
    }
}

public class RunnableTH{
    public static void main(String[] args) {
        myRunnable r = new myRunnable();

        Thread t1 =  new Thread(r);
        Thread t2 =  new Thread(r);

        System.out.println(t1.getName());
        System.out.println(t2.getName());

        t1.setName("Test1");
        t2.setName("Test2");

        System.out.println(t1.getName());
        System.out.println(t2.getName());
    }
}