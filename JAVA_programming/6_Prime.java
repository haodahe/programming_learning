import java.util.Scanner;
public class Prime {
   Prime(){
   }
   
   static boolean isPrime(int input){
       int number;
       
       for(int ia = 2; ia <= input / 2; ia ++){
           if(input %ia == 0){
               return(false);
           }           
       }
       return(true);
   }
   
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); 
       Prime r = new Prime();
       
       System.out.println("Input the number: ");
       int input = s.nextInt();
       boolean answer = r.isPrime(input);
       
       if(answer == false)
           System.out.println("The number " + input + " is not prime");
       else
           System.out.println("The number " + input + " is prime");
   }
}