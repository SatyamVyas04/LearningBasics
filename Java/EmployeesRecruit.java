// Pseudocode
// class Employees
//     variables
//     - name
//     - cwscore
//     - aptscore
//     - techscore
//     - intscore
//     - job_profile
//     methods
//     - const1 for programmer
//     - const2 for teamleader
//     - const3 for projectmng
//     - checkrecruitment based on profile
// class EmployeeRecruit
//     methods
//     - main
//         run a menu
//         input choices for scores to Enter
//         check respective job post
//         print req result
//         exit
         
import java.util.*;

public class EmployeesRecruit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("> Enter the number of Employees to check: ");
        int n = sc.nextInt();
        sc.nextLine(); //Buffer Clear

        Employees[] emps = new Employees[n];

        for(int i = 0; i<n; i++){
            System.out.println("\n---------------------------------------------");
            System.out.print("> Enter Name of Emp "+(i+1)+": ");
            String name = sc.nextLine();
            System.out.println("> Enter Job Profile of Emp "+(i+1)+": ");
            System.out.print("  P: Programmer,\n  T: Team Leader,\n  M: Project Manager: ");
            char jobprof = sc.next().charAt(0);
            System.out.println("\n> Enter Scores");

            if (jobprof == 'P'){
                System.out.print("> Enter Course Work Score: ");
                int cws = sc.nextInt();
                System.out.print("> Enter Aptitude Test Score: ");
                int apts = sc.nextInt();
                System.out.print("> Enter Technical Test Score: ");
                int tecs = sc.nextInt();
                System.out.print("> Enter Interview Score: ");
                int ints = sc.nextInt();
                emps[i] = new Employees(name, cws, apts, tecs, ints);
                sc.nextLine(); //Buffer Clear

            }else if (jobprof == 'T'){
                System.out.print("> Enter Technical Test Score: ");
                int tecs = sc.nextInt();
                System.out.print("> Enter Interview Score: ");
                int ints = sc.nextInt();
                emps[i] = new Employees(name, tecs, ints);
                sc.nextLine(); //Buffer Clear

            }else if (jobprof == 'M'){
                System.out.print("> Enter Interview Score: ");
                int ints = sc.nextInt();
                emps[i] = new Employees(name, ints);
                sc.nextLine(); //Buffer Clear
            }else{
                System.out.println("Incorrect Input!");
            }
        }

        System.out.println("\n>> Results: ");
        for(Employees i: emps){
            i.check_recruitment();
        }
        sc.close();
    }
} 

class Employees{
    String name;
    int cwscore, aptscore, techscore, intscore;
    boolean recruitement_status = false;
    String job_profile;
    
    Employees(String name, int c, int a, int t, int i){
        this.name = name;
        this.cwscore = c;
        this.aptscore = a;
        this.techscore = t;
        this.intscore = i;
        job_profile = "Programmer";
    }
    
    Employees(String name, int t, int i){
        this.name = name;
        this.techscore = t;
        this.intscore = i;
        job_profile = "TeamLeader";
    }
    
    Employees(String name, int i){
        this.name = name;
        this.intscore = i;
        job_profile = "ProjectManager";
    }
    
    void check_recruitment(){
        switch(this.job_profile){
            case "Programmer":
                if (this.cwscore + this.aptscore + this.techscore + this.intscore >= 80){
                    this.recruitement_status = true;
                }
                break;
            case "TeamLeader":
                if (this.techscore + this.intscore >= 85){
                    this.recruitement_status = true;
                }
                break;
            case "ProjectManager":
                if (this.intscore >= 90) this.recruitement_status = true;
                break;
            default:
                break;
        }
        if(this.recruitement_status){
            System.out.println(this.name+": Pass for "+this.job_profile + " post");
        }else{
            System.out.println(this.name+": Failed for "+this.job_profile + " post");
        }
    }
}
