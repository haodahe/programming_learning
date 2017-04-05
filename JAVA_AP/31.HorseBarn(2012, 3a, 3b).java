import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class HorseBarn {
   private Horse[] spaces;
   
   public HorseBarn(int number){
       spaces = new Horse[number];
   }
   
   public int findHorseSpase(String name){
       for(int i = 0; i < spaces.length; i ++){
           if(spaces[i] != null && spaces[i].getName().equals(name))
               return i;
       }
       return -1;
   }
   
   public void consolidate(){
       for(int i = 0; i < spaces.length; i ++){
           if(spaces[i] == null){
               for(int j = i + 1; j < spaces.length; j ++){
                   if(spaces[j] != null){
                       spaces[i] = spaces[j];
                       spaces[j] = null;
                   }
               }
           }
       }
   }
   
   public static void main(String[] args) {
       HorseBarn r = new HorseBarn(7);
       
       
   }
   
}