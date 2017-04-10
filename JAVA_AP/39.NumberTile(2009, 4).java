import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class NumberTile {
   private int up, right, down, left;
   
   public NumberTile(int a, int b, int c, int d){
       up = a;
       right = b;
       down = c;
       left = d;
   }
   
   public void rotate(){
       int number = up;
       up = left;
       left = down;
       down = right;
       right = number;
   }
   
   public int getLeft(){
       return left;
   }
   
   public int getRight(){
       return right;
   }
}