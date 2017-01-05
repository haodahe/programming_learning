import java.util.Scanner;
public class LeapYear {  
  LeapYear(){
  }
  
  static boolean isLeapYear(int year){
    if(year %4 == 0){
        if(year %100 == 0){
          if(year %400 == 0){
              return(true);
          }
          else{
              return(false);
          }
        }
        else{
            return(true);
        }
    }
    else{
        return(false);
    }
  }
  
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); 
       LeapYear r = new LeapYear();
       
       System.out.println("Input year: ");
       int year = s.nextInt();
       boolean answer = r.isLeapYear(year);
       
       if(answer == true)
           System.out.println("The year " + year + " is a leap year.");
       else
           System.out.println("The year " + year + " is not a leap year.");
   }
}