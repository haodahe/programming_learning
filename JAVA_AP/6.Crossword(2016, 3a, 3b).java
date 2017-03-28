import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class Crossword {
   private Square[][] puzzle;
   Crossword(boolean [][] blackSquares){
       int number = 1;
       puzzle = new Square[blackSquares.length][blackSquares[0].length];
       for(int i = 0; i < blackSquares.length; i ++)
           for(int j = 0; j < blackSquares[0].length; j ++){
               puzzle[i][j] = new Square(blackSquares[i][j], 0);
               if(toBeLabeled(i, j, blackSquares)){
                   puzzle[i][j] = new Square(blackSquares[i][j], number);
                   number ++;
               }
           }
   }
   
   private boolean toBeLabeled(int r, int c, boolean [][] blackSquares){
       if(blackSquares[r][c])
           return false;
       if(r == 0 || blackSquares[r - 1][c])
           return true;
       if(c == 0 || blackSquares[r][c - 1])
           return true;
       return false;
   }
   /*
   public static void main(String[] args) {
       boolean[][] blackSquares = new boolean[3][3];
        
       for(int i = 0; i < 3; i ++)
           for(int j = 0; j < 3; j ++)
               blackSquares[i][j] = false;
       blackSquares[1][1] = true;
       
       Crossword r = new Crossword(blackSquares);
       
       for(int i = 0; i < 3; i ++){
           for(int j = 0; j < 3; j ++)
               System.out.print(r.puzzle[i][j].num + " ");
           System.out.println("");
       }
   }
   */
}