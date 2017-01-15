import java.util.Random;
public class CityPlanning {
   Random rand = new Random();
   int[][] footTraffic;
   int first_nu, second_nu;
   
   CityPlanning(int width, int length){
       footTraffic = new int [width][length];
       this.first_nu = width;
       this.second_nu = length;
       
       for(int ia = 0; ia < this.first_nu; ia ++){
           for(int ib = 0; ib < this.second_nu; ib ++){
               int number1 = rand.nextInt(100);
               double number2 = rand.nextDouble();
               
               if(number2 < 0.2){
                   footTraffic[ia][ib] = 0;
               }
               else{
                   footTraffic[ia][ib] = number1;
               }
           }
       }
   }
   
   void printMap(){
       for(int ia = 0; ia < this.first_nu; ia ++){
           for(int ib = 0; ib < this.second_nu; ib ++){
               if(footTraffic[ia][ib] >= 10){
                   System.out.print(footTraffic[ia][ib] + " ");
               }
               else{
                   System.out.print("0" + footTraffic[ia][ib] + " ");
               }
           }
           System.out.println("");
       }       
   }
   
   String findBestLocation(){
       int number1, number2, number3;
       number1 = number2 = number3 = 0;
       
       for(int ia = 0; ia < this.first_nu; ia ++){
           for(int ib = 0; ib < this.second_nu; ib ++){
               if(footTraffic[ia][ib] > number3){
                   number1 = ia;
                   number2 = ib;
                   number3 = footTraffic[ia][ib];
               }
           }
       }
       return("(" + number1 + "," + number2 + ")");
   }
   
   double calculateValue(int number1, int number2){
       int sum = 0;
       int number = 0;
       
       if(number1 > 0){
           number++;
           sum += footTraffic[number1 - 1][number2];
       }
       if(number2 > 0){
           number++;
           sum += footTraffic[number1][number2 - 1];
       }
       if(number1 < this.first_nu - 1){
           number++;
           sum += footTraffic[number1 + 1][number2];
       }
       if(number2 < this.second_nu - 1){
           number++;
           sum += footTraffic[number1][number2 + 1];
       }
       
       double answer = sum / number;
       
       return(answer);
   }
     
   public static void main(String[] args) {
       
   }
}