import java.util.Random;
class numGenThread extends Thread{
    public static int n;
    public void run(){
        Random random = new Random();        
        n = random.nextInt(100);
        System.out.println("\nNumGenThread: " + n);
    }
}

class numSquareThread extends numGenThread{
    @Override
    public void run(){
        System.out.println("NumSquareThread: " + n*n);
    }
}

class numCubeThread extends numGenThread{
    @Override
    public void run(){
        System.out.println("NumCubeThread: " + n*n*n);
    }
}

public class Multithread {
    public static void main(String[] args) {
        numGenThread t1 = new numGenThread();
        numGenThread t2 = new numSquareThread();
        numGenThread t3 = new numCubeThread();

        for(int i = 0; i<10; i++){
            t1.run();
            t2.run();
            t3.run();
            
            try{
                t1.sleep(1000);
            }
            catch(InterruptedException e){
                System.out.println(e.getStackTrace());
            }
        }
        System.out.println("End of Program");
    }
}
