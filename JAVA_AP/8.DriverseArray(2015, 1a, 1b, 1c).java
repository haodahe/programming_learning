import java.io.*;
import java.util.Random;
public class DriverseArray {
   DriverseArray(){
   }
   
   public static int arraySum(int[] arr){
       int sum = 0;
       for(int i = 0; i < arr.length; i ++){
           sum += arr[i];
       }
       return sum;
   }
   
   public static int[] rowSums(int[][] arr2D){
       int[] answer = new int [arr2D.length];
       
       for(int i = 0; i < arr2D.length; i ++){
           answer[i] = arraySum(arr2D[i]);
       }
       
       return answer;
   }
   
   public static boolean isDiverse(int [][] arr2D){
       int[] answer = rowSums(arr2D);
       
       for(int i = 0; i < answer.length; i ++){
           for(int j = i + 1; j < answer.length; j ++){
               if(answer[i] == answer[j])
                   return false;
           }
       }
       return true;
   }
   
   public static void main(String[] args) {
       DriverseArray r = new DriverseArray();
       
       int[][] arr = new int [3][3];
       arr[0][0] = 1;
       arr[0][1] = 2;
       arr[0][2] = 3;
       arr[1][0] = 4;
       arr[1][1] = 5;
       arr[1][2] = 6;
       arr[2][0] = 3;
       arr[2][1] = 3;
       arr[2][2] = 1;
       
       System.out.println(r.isDiverse(arr));
   }
}