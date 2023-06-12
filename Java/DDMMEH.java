import java.util.Scanner;

class MonthError extends Exception{
    public MonthError(String msg){
        super(msg);
    }
}

class DayError extends Exception{
    public DayError(String msg){
        super(msg);
    }
}

public class DDMMEH {
    public static String changeformat(String numericDate) throws MonthError, DayError{
        String[] months = {
                "", "January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"
        };

        try{
            String[] parts = numericDate.split("/");
            int month = Integer.parseInt(parts[0]);
            int day = Integer.parseInt(parts[1]);

            if(month < 1 || month > 12){
                throw new MonthError("Invalid Month: " + month);
            }
            if(day < 1 || day > 31){
                throw new DayError("Invalid Day: " + day);
            }
            if(month == 2 && day > 29){
                throw new DayError("Invalid Day: " + day);
            }
            if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30){
                throw new DayError("Invalid Day: " + day);
            }

            return months[month] + " " + day;
        }
        
        catch (NumberFormatException e){
            throw new NumberFormatException("Invalid Date Format: " + numericDate);
        }
    }

    public static void main(String[] args){
        String date;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the number of dates you want to enter: ");
        int n = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i<n; i++){
            date = sc.nextLine();
            try{
                String orderedDate = changeformat(date);
                System.out.println(date + " corresponds to " + orderedDate);
            }
            
            catch (MonthError e) {
                System.out.println("Error!!! --->" + date + ": " + e.getMessage());
            }catch (DayError e) {
                System.out.println("Error!!! --->" + date + ": " + e.getMessage());
            }catch (NumberFormatException e) {
                System.out.println("Error!!! --->" + date + ": " + e.getMessage());
            }
        }
    }
}
