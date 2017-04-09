import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class CubeList {
   CubeList(){
   }
   
   public static int[] getCubeTosses(NumberCube cube, int numTosses){
       int answer[] = new int [numTosses];
       
       for(int i = 0; i < numTosses; i ++){
           answer[i] = cube.toss();
       }
       
       return answer;
   }
   
   public static int getLongestRun(int[] values){
     int number = -1;
     int number2 = 1;
     for(int i = 0; i < values.length - 1; i ++){
         if(values[i] == values[i + 1])
             number2 ++;
         else{
             if(number2 > number && number2 != 1){
                 number = number2;
             }
             number2 = 1;
         }
     }
     
     if(number2 > number && number2 != 1){
         number = number2;
         number2 = 1;
     }
     
     return number;
   }
   
   public static void main(String[] args) {
       CubeList r = new CubeList();
       NumberCube a = new NumberCube();
       int answer[] = new int [6];
       
       answer = r.getCubeTosses(a, 6);
       
       for(int i = 0; i < 6; i ++)
           System.out.print(answer[i] + " ");
       
       System.out.println();
       
       System.out.println(r.getLongestRun(answer));
   }
}