import java.io.*;
import java.util.Random;
public class RandomStringChooser {
   private int check[];
   private String array[];
   RandomStringChooser(String a[]){
       this.array = new String [a.length];
       check = new int[a.length];
       for(int i = 0; i < a.length; i++){
           check[i] = 0;
           array[i] = a[i];
       }
   }
   
   public String getNext(){
       for(int i = 0; i < array.length; i++){
           if(check[i] == 0){
               while(true){
                   Random randomGenerator = new Random();
                   int number = randomGenerator.nextInt(array.length);
                   if(check[number] == 0){
                       check[number] = 1;
                       return array[number];
                   }
               }
           }
       }
       return "NONE";
   }
   /*
   public static void main(String[] args) {
       String[] wordArray = {"a", "b", "c", "d", "e"};
       RandomStringChooser sChooser = new RandomStringChooser(wordArray);
       for(int k = 0; k < 7; k ++){
           System.out.print(sChooser.getNext() + " ");
       }
       System.out.println("");
   }
   */
}