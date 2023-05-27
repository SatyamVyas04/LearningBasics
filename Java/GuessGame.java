import java.util.*;

abstract class Player{
    String name;
    abstract int getGuess();
    Scanner sc = new Scanner(System.in);
}

class HumanPlayer extends Player{
    HumanPlayer(String name){
        this.name = name;
    }

    int getGuess(){
        int guess;
        System.out.print("> Enter your Guess " + this.name + ": ");
        guess = sc.nextInt();
        sc.nextLine(); // Buffer Clear
        return guess;
    }
}

class ComputerPlayer extends Player{
    ComputerPlayer(String name){
        this.name = name;
    }
    int getGuess(){
        int guess;
        System.out.println("> " + this.name + " is guessing...");
        Random random = new Random();
        guess = random.nextInt(100) + 1;
        System.out.println("> " + this.name + " guessed " + guess);
        return guess;
    }
}

public class GuessGame{
    public static void main(String[] args) {
        int gamemode = 1;
        Player Player1, Player2;
        String p1, p2;
        Scanner sc = new Scanner(System.in);

        System.out.println("---------- Welcome to the Guess Game! ----------");
        while(gamemode!=0){
            System.out.println("\n>>> Starting a New Game... ");
            System.out.println("> Select the Mode you want to play: ");
            System.out.println("> Enter 1 for Player 1 vs Player 2  ");
            System.out.println("> Enter 2 for Player 1 vs Computer ");
            System.out.println("> Enter 3 for Computer 1 vs Computer 2 ");
            System.out.println("> Enter 0 to Quit ");
            System.out.print("> ");

            gamemode = sc.nextInt();
            sc.nextLine(); // Buffer Clear

            switch (gamemode) {
                case 1:
                    System.out.println(">>> Player 1 vs Player 2 ");
                    System.out.print("> Player 1 Name: ");
                    p1 = sc.nextLine();
                    System.out.print("> Player 2 Name: ");
                    p2 = sc.nextLine();

                    Player1 = new HumanPlayer(p1);
                    Player2 = new HumanPlayer(p2);
                    
                    play(Player1, Player2);
                    break;

                case 2: 
                    System.out.println(">>> Player 1 vs Computer ");
                    System.out.print("> Player 1 Name: ");
                    p1 = sc.nextLine();

                    Player1 = new HumanPlayer(p1);
                    Player2 = new ComputerPlayer("Computer");
                    
                    play(Player1, Player2);
                    break;
                
                case 3: 
                    System.out.println(">>> Computer 1 vs Computer 2 ");
                    Player1 = new ComputerPlayer("Computer1");
                    Player2 = new ComputerPlayer("Computer2");
                    
                    play(Player1, Player2);
                    break;
                
                case 0:
                    System.out.println("\n---------- Thanks for Playing! ---------- ");
                    break;

                default:
                    System.out.println(">>> Invalid Mode! ");
                    break;
            }
        }
    }

    static void play(Player player1, Player player2){
        int guess1=0, guess2=0;
        boolean anscheck;
        String winner = "NULL";

        Random random = new Random();
        // int answer = random.nextInt(100) + 1;
        int answer = 10;
        System.out.println("\n> Random Number between 1 to 100 has been chosen!");

        while(true){
            System.out.println("\n> " + player1.name + "'s Turn:- ");
            guess1 = player1.getGuess();
            if(Checkanswer(guess1, answer)){
                winner = player1.name;
                break;
            }

            System.out.println("\n> " + player2.name + "'s Turn:- ");
            guess2 = player2.getGuess();
            if(Checkanswer(guess2, answer)){
                winner = player2.name;
                break;
            }
        }

        System.out.println("\n>>> " + winner + " Wins!!!");
    }

    static boolean Checkanswer(int guess,int answer){
        System.out.println("> Checking last Guess...");
        if (guess == answer){
            return true;
        }
        return false;
    }
}