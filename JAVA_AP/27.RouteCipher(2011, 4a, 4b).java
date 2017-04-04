import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class RouteCipher {
   private String [][] letterBlock;
   private int numRows;
   private int numCols;
   
   RouteCipher(int numRows, int numCols){
       letterBlock = new String [numRows][numCols];
       this.numRows = numRows;
       this.numCols = numCols;
   }
   
   private void fillBlock(String str){
       int number  = 0;
       for(int i = 0; i < numRows; i ++)
           for(int j = 0; j < numCols; j ++){
               if(number < str.length())
                   letterBlock[i][j] = str.substring(number, number + 1);
               else
                   letterBlock[i][j] = "A";
               
               number ++;
           }
   }
   
   private String encryptMessage(String message){
       String answer = "";
       int number = 0;
       int number2 = 0;
       while(true){
           if(number + numRows * numCols < message.length())
               fillBlock(message.substring(number, number + numRows * numCols));
           else{
               fillBlock(message.substring(number, message.length()));
               number2 = 1;
           }
           
           number += numRows * numCols;
           
           
           for(int i = 0; i < numCols; i ++)
               for(int j = 0; j < numRows; j ++)
                   answer += letterBlock[j][i];
           
           if(number2 == 1)
               break;
       }
       return answer;
   }
   
   public static void main(String[] args) {
       RouteCipher r = new RouteCipher(2, 3);
       
       System.out.println(r.encryptMessage("Meet at midnight"));
       
   }
}