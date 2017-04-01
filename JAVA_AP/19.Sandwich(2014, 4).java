import java.io.*;
import java.lang.*;
import java.util.*;
class Sandwich implements MenuItem {
   String name;
   double price;
   
   Sandwich(String name, double price){
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