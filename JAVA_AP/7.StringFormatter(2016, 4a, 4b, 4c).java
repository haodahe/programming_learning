import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class StringFormatter {
   StringFormatter(){
   }
   
   public static int totalLetters(List<String> wordList){
       int answer = 0;
       for(int i = 0; i < wordList.size(); i++){
           answer += wordList.get(i).length();
       }
       return answer;
   }
   
   public static int basicGapWidth(List<String> wordList, int formattedLen){
       int answer = formattedLen - totalLetters(wordList);
       int space = wordList.size() - 1;
       
       return answer / space;
   }
   
   public static int leftoverSpaces(List<String> wordList, int formattedLen){
       int answer = formattedLen - totalLetters(wordList);
       int space = wordList.size() - 1;
       
       return answer % space;
   }
   
   public static String format(List<String> wordList, int formattedLen){
       String answer = "";
       int space = basicGapWidth(wordList, formattedLen);
       int leftover = leftoverSpaces(wordList, formattedLen);
       
       for(int i = 0; i < wordList.size(); i ++){
           answer += wordList.get(i);
           if(i == wordList.size() - 1)
               break;
           for(int j = 0; j < space; j ++)
               answer += " ";
           if(leftover > 0){
               answer += " ";
               leftover --;
           }
       }
       return answer;
   }
   
   public static void main(String[] args) {
       StringFormatter r = new StringFormatter();
       List<String> wordList = new ArrayList<String>(4);
       
       wordList.add("AP");
       wordList.add("COMP");
       wordList.add("SCI");
       wordList.add("ROCKS");
       
       System.out.println(format(wordList, 20));
   }
}