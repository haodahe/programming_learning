import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class MultipleGroups {
   private List<NumberGroup> groupList;
   
   MultipleGroups(){
     groupList = new ArrayList<NumberGroup>();
   }
   
   public boolean contains(int number){
       for(int i = 0; i < groupList.size(); i ++){
           if(groupList.get(i).contains(number))
               return true;
       }
       return false;
   }
   
   public static void main(String[] args) {
       MultipleGroups r = new MultipleGroups();
       Range a = new Range(5, 8);
       Range b = new Range(10, 12);
       Range c = new Range(1, 6);
       
       r.groupList.add(a);
       r.groupList.add(b);
       r.groupList.add(c);
       
       System.out.println(r.contains(2));
       System.out.println(r.contains(9));
       System.out.println(r.contains(6));
   }
   
}