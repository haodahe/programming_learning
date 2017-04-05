import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class ClimbInfo {
   String name;
   int time;
   
   public ClimbInfo(String peakName, int climbTime){
       name = peakName;
       time = climbTime;
   }
   
   public String getName(){
       return name;
   }
   
   public int getTime(){
       return time;
   }
}