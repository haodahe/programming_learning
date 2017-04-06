import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class GrayImage{
   public static final int BLACK = 0;
   public static final int WHITE = 255;
   private int[][] pixelValues;
   
   GrayImage(int a, int b){
       pixelValues = new int [a][b];
   }
   
   public int countWhitePixels(){
       int number = 0;
       for(int i = 0; i < pixelValues.length; i ++){
           for(int j = 0; j < pixelValues[0].length; j ++){
               if(pixelValues[i][j] == WHITE)
                   number ++;
           }
       }
       return number;
   }
   
   public void processImage(){
       for(int i = 0; i < pixelValues.length - 2; i ++){
           for(int j = 0; j < pixelValues[0].length - 2; j ++){
               pixelValues[i][j] -= pixelValues[i + 2][j + 2];
               if(pixelValues[i][j] < 0)
                   pixelValues[i][j] = 0;
           }
       }
   }
   
   public static void main(String[] args) {
       GrayImage r = new GrayImage(4, 5);
       
       r.pixelValues[0][0] = 221;
       r.pixelValues[0][1] = 184;
       r.pixelValues[0][2] = 178;
       r.pixelValues[0][3] = 84;
       r.pixelValues[0][4] = 135;
       
       r.pixelValues[1][0] = 84;
       r.pixelValues[1][1] = 255;
       r.pixelValues[1][2] = 255;
       r.pixelValues[1][3] = 130;
       r.pixelValues[1][4] = 84;
       
       r.pixelValues[2][0] = 78;
       r.pixelValues[2][1] = 255;
       r.pixelValues[2][2] = 0;
       r.pixelValues[2][3] = 0;
       r.pixelValues[2][4] = 78;
       
       r.pixelValues[3][0] = 84;
       r.pixelValues[3][1] = 130;
       r.pixelValues[3][2] = 255;
       r.pixelValues[3][3] = 130;
       r.pixelValues[3][4] = 84;
       
       r.processImage();
       
       for(int i = 0; i < 4; i ++){
           for(int j = 0; j < 5; j ++)
               System.out.print(r.pixelValues[i][j] + "  ");
           System.out.println();
       }
   }
}