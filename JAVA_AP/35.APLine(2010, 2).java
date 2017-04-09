import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class APLine {
   public static int a, b, c;
   
   APLine(int a, int b, int c){
       this.a = a;
       this.b = b;
       this.c = c;
   }
   
   public static double getSlope (){
       double slope = a * -1;
       slope /= b;
       return slope;
   }
   
   public static boolean isOnLine (int x, int y){
       if(x * a + y * b + c == 0)
           return true;
       return false;
   }
   
   public static void main(String[] args) {
       APLine r = new APLine(5, 4, -17);
       
       System.out.println(r.getSlope());
       System.out.println(r.isOnLine(5, -2));
   }
}