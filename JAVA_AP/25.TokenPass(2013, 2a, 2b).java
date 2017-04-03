import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class TokenPass {
   public int[] board;
   private int currentPlayed;
   
   TokenPass(int playerCount){
       board = new int[playerCount];
       for(int i = 0; i < playerCount; i ++){
           Random randomGenerator = new Random();
           board[i] = randomGenerator.nextInt(10) + 1;
       }
   }
   
   public void distributeCurrentPlayerTokens(){
       int number = board[currentPlayed];
       int number2 = currentPlayed + 1;
       for(int i = 0; i < number; i ++){
           if(number2 == board.length)
               number2 = 0;
           
           board[number2] ++;
           board[currentPlayed] --;
           
           number2 ++;
       }
   }
   
   public static void main(String[] args) {
       TokenPass r = new TokenPass(10);
       
       r.currentPlayed = 5;
       
       for(int i = 0; i < 10; i ++){
           System.out.print(r.board[i] + " ");
       }
       System.out.println();
       
       r.distributeCurrentPlayerTokens();
       
       for(int i = 0; i < 10; i ++){
           System.out.print(r.board[i] + " ");
       }
   }
}