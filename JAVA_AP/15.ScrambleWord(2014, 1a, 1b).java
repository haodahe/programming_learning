import java.io.*;
import java.lang.*;
import java.util.*;
public class ScrambleWord {
   ScrambleWord(){
   }
   
   public static String scrambleWord(String word){       
       for(int i = 0; i < word.length() - 1; i ++){
           if(word.charAt(i) == 'A' && word.charAt(i + 1) != 'A'){
               word = word.substring(0, i) + word.charAt(i + 1) + "A" + word.substring(i + 2);
               i ++;
           }
       }
       return word;
   }
   
   public static void scrambleOrRemove(List<String> wordList){
       for(int i = 0; i < wordList.size(); i ++){
           if(wordList.get(i).equals(scrambleWord(wordList.get(i)))){
               wordList.remove(i);
               i --;
           }
           else
               wordList.set(i, scrambleWord(wordList.get(i)));
       }
   }
   
   public static void main(String[] args) {
       ScrambleWord r = new ScrambleWord();
       List<String> wordList = new ArrayList<String>();
       
       wordList.add("TAN");
       wordList.add("ABRACADABRA");
       wordList.add("WHOA");
       wordList.add("APPLE");
       wordList.add("EGGS");
       
       r.scrambleOrRemove(wordList);
       
       for(int i = 0; i < wordList.size(); i ++)
           System.out.print(wordList.get(i) + " ");
   }
}