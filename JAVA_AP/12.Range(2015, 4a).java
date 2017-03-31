import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class Range implements NumberGroup {
   int [] group;
   
   Range(int a, int b){
       group = new int [b - a + 1];
       for(int i = 0; i < b - a + 1; i ++){
           group[i] = a + i;
       }
   }
   
   public boolean contains(int number){
       for(int i = 0; i < group.length; i ++){
           if(group[i] == number)
               return true;
       }
       return false;
   }
   /*
   public static void main(String[] args) {
       Range r = new Range(-3, 2);
       
       for(int i = 0; i < 6; i ++)
           System.out.print(r.group[i] + "  ");
       System.out.println("");
       
       System.out.println(r.contains(3));
   }
   */
}