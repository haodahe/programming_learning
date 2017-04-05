import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class ClimbingClub {
   private List<ClimbInfo> climbList;
   
   public ClimbingClub(){
       climbList = new ArrayList<ClimbInfo>();
   }
   
   public void addClimb(String peakName, int climbTime){
       int i = 0;
       for(i = 0; i < climbList.size(); i ++){
           if(climbList.get(i).getName().compareTo(peakName) > 0){
               break;
           }
       }
       
       ClimbInfo a = new ClimbInfo(peakName, climbTime);
       climbList.add(i, a);
   }

   public static void main(String[] args) {
       ClimbingClub r = new ClimbingClub();
       
       r.addClimb("Monadnock", 274);
       r.addClimb("Whiteface", 301);
       r.addClimb("Algonquin", 225);
       r.addClimb("Monadnock", 344);
       
       for(int i = 0; i < r.climbList.size(); i ++)
           System.out.println(r.climbList.get(i).getName());
       
       //C :
       //(i)  :  No
       //(ii) :  Yes
   }
}