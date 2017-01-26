import java.lang.String;
public class Euclid {
   static int gcd (int a, int b){
       if(a % b == 0)
           return(b);    
       return(gcd(b, a % b));
   }
   
   static double geometric (int number){
       if(number == 1)
           return(1);
       
       double answer;
       int number_2 = (int)Math.pow(2, number - 1);
       answer = (double)1 / (double)number_2;
       answer += geometric(number - 1);
       return(answer);
   }
   
   static double basel(int number){
       if(number == 1)
           return(1);
       else{
           double number_2 = (double)1 / (double)(number * number);
           number_2 = basel(number - 1) + number_2;
           return(number_2);
       }
   }
   
   static String scrambler (String input){
       if(input.length() == 0)
           return("");
       if(input.length() == 1)
           return(input);
       if(input.length() == 2){
           String input_2 = new StringBuffer(input).reverse().toString();
           return(input_2);
       }
       
       String input_2 = input.substring(input.length() - 1, input.length()) + scrambler(input.substring(1, (int)input.length() / 2));
       input_2 += scrambler(input.substring((int)input.length() / 2, input.length() - 1)) + input.substring(0, 1);
       return(input_2);
   }
   
   
   public static void main(String[] args) {
       Euclid r = new Euclid();
   }
}