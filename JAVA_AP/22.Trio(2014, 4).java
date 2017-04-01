import java.io.*;
import java.lang.*;
import java.util.*;
class Trio implements MenuItem {
   Sandwich sandwich;
   Salad salad;
   Drink drink;
   
   Trio(Sandwich sandwich, Salad salad, Drink drink){
       this.sandwich = sandwich;
       this.salad = salad;
       this.drink = drink;
   }
   
   public String getName(){
       String name = "";
       
       name += sandwich.getName() + "/";
       name += salad.getName() + "/";
       name += drink.getName();
       
       return name;
   }
   
   public double getPrice(){
       double number = sandwich.getPrice();
       if(number > salad.getPrice())
           number = salad.getPrice();
       
       if(number > drink.getPrice())
           number = drink.getPrice();
       
       number = sandwich.getPrice() + salad.getPrice() + drink.getPrice() - number;
       
       return number;
   }
   
   public static void main(String[] args) {
       Sandwich cheeseburger = new Sandwich("cheeseburger", 2.75);
       Sandwich club_sandwich = new Sandwich("club sandwich", 2.75);
       Salad spinach_salad = new Salad("spinach salad", 1.25);
       Salad coleslaw = new Salad("coleslaw", 1.25);
       Drink orange_soda = new Drink("orange soda", 1.25);
       Drink cappuccino = new Drink("cappuccino", 3.50);
       
       Trio r = new Trio(cheeseburger, coleslaw, orange_soda);
       
       System.out.println(r.getName());
       System.out.println(r.getPrice());
       
   }
}