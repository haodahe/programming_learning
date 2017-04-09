import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class Trail {
   public int[] markers;
   
   Trail(int number){
       markers = new int[number];
   }
   
   public boolean isLevelTrailSegment(int start, int end){
       int big, small;
       big = small = markers[start];
       
       for(int i = start; i <= end; i ++){
           if(big < markers[i])
               big = markers[i];
           if(small > markers[i])
               small = markers[i];
       }
       
       if(big - small <= 10)
           return true;
       return false;
   }
   
   public boolean isDiffcult(){
       int number = 0;
       for(int i = 0; i < markers.length - 1; i ++){
           if(markers[i] - markers[i + 1] >= 30 || markers[i] - markers[i + 1] <= -30){
               number ++;
               if(number == 3)
                   return true;
           }
       }
       return false;
   }
   
   public static void main(String[] args) {
       Trail r = new Trail(5);
       
       r.markers[0] = 1;
       r.markers[1] = 49;
       r.markers[2] = 34;
       r.markers[3] = 34;
       r.markers[4] = 30;
       
       System.out.println(r.isDiffcult());
   }
}