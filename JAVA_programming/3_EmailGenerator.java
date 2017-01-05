import java.util.Scanner;
import java.lang.String;
public class EmailGenerator {
  EmailGenerator(){
  }
  
  static String makeUserName(String first, String second) {
      int number = second.length();
      if(number == 7){
          String a = first.charAt(0) + second;
          return a;
      }
      else{
          if(number > 7){
              String a = first.charAt(0) + second.substring(0,7);
              return a;
          }
          else{
              int number2 = first.length();
              number = 8 - number;
              if(number2 > number){
                  String a = first.substring(0, number) + second;
                  return a;
              }
              else{
                  number = 8 - number2 - second.length();
                  String x = "xxxxxxxx";
                  String a = first + second + x.substring(0, number);
                  return a;
              }
          }
      }
  }
  static String makeEmail(String first, String second){
      return first + "@" + second;
  }
   
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); 
       EmailGenerator r = new EmailGenerator();
       String input;
       
       System.out.println("input your name: ");
       
       input = r.makeUserName(s.nextLine(), s.nextLine());
       
       input = r.makeEmail(input, "purdue.edu");
       input = input.toLowerCase();
       
       System.out.println("This user's e-mail is: " + input); 
   }
}