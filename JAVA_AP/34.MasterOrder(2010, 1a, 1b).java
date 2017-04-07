import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class MasterOrder {
   private List<CookieOrder> orders;
   
   public MasterOrder(){
       orders = new ArrayList<CookieOrder>();
   }
   
   public void addOrder(CookieOrder theOrder){
       orders.add(theOrder);
   }
   
   public int getTotalBoxes(){
       int answer = 0;
       
       for(int i = 0; i < orders.size(); i ++){
           answer += orders.get(i).getNum();
       }
       
       return answer;
   }
   
   public int removeVariety(String cookieVar){
       int number = 0;
       List<CookieOrder> orders2 = new ArrayList<CookieOrder>();
       for(int i = 0; i < orders.size(); i ++){
           if(orders.get(i).getVariety().equals(cookieVar)){
               number ++;
           }
           else{
               orders2.add(orders.get(i));
           }
       }
       
       orders = orders2;
       
       return number;
   }
   
   public static void main(String[] args) {
       MasterOrder r = new MasterOrder();
       
       CookieOrder a = new CookieOrder("A", 1);
       CookieOrder b = new CookieOrder("B", 2);
       CookieOrder c = new CookieOrder("C", 3);
       CookieOrder d = new CookieOrder("A", 4);
       CookieOrder e = new CookieOrder("E", 5);
       
       r.addOrder(a);
       r.addOrder(b);
       r.addOrder(c);
       r.addOrder(d);
       r.addOrder(e);
       
       System.out.println(r.getTotalBoxes());
       System.out.println(r.removeVariety("A"));
       
       
       
   }
}