import java.io.*;
import java.lang.*;
import java.util.*;
class Salad implements MenuItem {
   String name;
   double price;
   
   Salad(String name, double price){
       this.name = name;
       this.price = price;
   }
   
   public String getName(){
       return name;
   }
   
   public double getPrice(){
       return price;
   }
}