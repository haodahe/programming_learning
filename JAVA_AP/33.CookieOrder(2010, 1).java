import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class CookieOrder {
   String variety;
   int numBoxes;
   
   public CookieOrder(String variety, int numBoxes){
       this.variety = variety;
       this.numBoxes = numBoxes;
   }
   
   public String getVariety(){
       return variety;
   }
   
   public int getNum(){
       return numBoxes;
   }
}