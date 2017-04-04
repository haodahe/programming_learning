import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class SkyView {
   private double[][] view;
   
   public SkyView(int numRows, int numCols, double[] scanned){
       view = new double[numRows][numCols];
       int number = 0;
       int number2;
       for(int i = 0; i < numRows; i ++){
           for(int j = 0; j < numCols; j ++){
               number2 = j;
               if(i % 2 == 1){
                   number2 = numCols - 1 - j;
               }
               
               view[i][number2] = scanned[number];
               number ++;
           }
       }
   }
   
   public static void main(String[] args) {
       double[] scanned = new double[6];
       
       scanned[0] = 0.3;
       scanned[1] = 0.7;
       scanned[2] = 0.8;
       scanned[3] = 0.4;
       scanned[4] = 1.4;
       scanned[5] = 1.1;
       
       SkyView r = new SkyView(3, 2, scanned);
       
       for(int i = 0; i < 3; i ++){
           for(int j = 0; j < 2; j ++)
               System.out.print(r.view[i][j] + " ");
           System.out.println();
       }
   }
}