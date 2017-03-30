import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class HiddenWord {
   public static String str;
   
   HiddenWord(String str){
       this.str = str;
   }
   
   public static String getHint(String input){
       String answer = "";
       for(int i = 0; i < input.length(); i ++){
           int number = 0;
           if(input.charAt(i) == str.charAt(i)){
               answer += input.charAt(i);
           }
           if(input.charAt(i) != str.charAt(i)){
               for(int j = 0; j < input.length(); j ++){
                   if(input.charAt(i) == str.charAt(j)){
                       number = 1;
                       break;
                   }
               }
               
               if(number == 1)
                   answer += "+";
               else
                   answer += "*";
           }
       }
       return answer;
   }
  
   
   public static void main(String[] args) {
       HiddenWord r = new HiddenWord("HARPS");
       
       System.out.println(r.getHint("AAAAA"));
       System.out.println(r.getHint("HELLO"));
       System.out.println(r.getHint("HEART"));
       System.out.println(r.getHint("HARMS"));
       System.out.println(r.getHint("HARPS"));
   }
}