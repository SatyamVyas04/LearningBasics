// Pseudocode
// class movie
//     variables
//     - name
//     - type
//     - hero
//     - heroine
//     - budget
// class main
//     methods
//     - menu for input
//     - object array movie
//     - sort and print
//     - gg

import java.util.*;

public class MovieRate{
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        
        System.out.print("Enter number of Movies: ");
        int n = sc.nextInt();
        sc.nextLine(); //buffer clear
        
        Movie[] movies = new Movie[n];
        
        for(int i = 0; i<n; i++){
        	System.out.println("\n-----------Movie Details----------");
            System.out.print("Enter Movie "+(i+1)+" Name: ");
            String name = sc.nextLine();
            System.out.print("Enter Movie "+(i+1)+" Type: ");
            String type = sc.nextLine();
            System.out.print("Enter Hero "+(i+1)+" Name: ");
            String hero = sc.nextLine();
            System.out.print("Enter Heroine "+(i+1)+" Name: ");
            String heroine = sc.nextLine();
            System.out.print("Enter Movie "+(i+1)+" Budget: ");
            int budget = sc.nextInt();
            sc.nextLine(); //buffer clear
            System.out.print("\n");
            
            movies[i] = new Movie(name, type, hero, heroine, budget);
        }
        // Ascending sort
        for (int i = 0; i<n-1; i++){
        	for(int j = i+1; j<n; j++){
        		if(movies[i].budget>movies[j].budget){
        			Movie temp;
        			temp = movies[i];
        			movies[i] = movies[j];
        			movies[j] = temp;
        		}
        	}
        }
        System.out.println("+------------------- Movie Details ------------------------+");
        System.out.printf("|%-3s|%-10s|%-10s|%-10s|%-10s|%-10s|\n", "Sr", "Name", "Type", "Hero", "Heroine", "Budget");
        System.out.println("+----------------------------------------------------------+");
        int count = 1;
        for(Movie m: movies){
        	System.out.printf("|%-3d|%-10s|%-10s|%-10s|%-10s|%-10d|\n", count, m.name, m.type, m.hero, m.heroine, m.budget);
        	count++;
        }
        System.out.println("+----------------------------------------------------------+");
        sc.close();
    }
}


class Movie{
    String name;
    String type;
    String hero;
    String heroine;
    int budget;
    Movie(String name, String type, String hero, String heroine, int budget){
        this.name = name;
        this.type = type;
        this.hero = hero;
        this.heroine = heroine;
        this.budget = budget;       
    }
}
