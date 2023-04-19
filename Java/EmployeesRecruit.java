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
        Employees emp1 = new Employees("A", 10, 20, 30, 10);
        Employees emp2 = new Employees("B", 10, 20, 30, 30);
        Employees emp3 = new Employees("C", 40, 40);
        Employees emp4 = new Employees("D", 40, 50);
        Employees emp5 = new Employees("E", 10);
        Employees emp6 = new Employees("F", 100);
        emp1.check_recruitment();
        emp2.check_recruitment();
        emp3.check_recruitment();
        emp4.check_recruitment();
        emp5.check_recruitment();
        emp6.check_recruitment();
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
        this.techscore = t;
        this.intscore = i;
        job_profile = "ProjectManager";
    }
    
    void check_recruitment(){
        switch(this.recruitement_status){
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
            System.out.println(this.name": Pass for "+this.job_profile + " post");
        }else{
            System.out.println(this.name": Failed for "+this.job_profile + " post");
        }
    }
}
