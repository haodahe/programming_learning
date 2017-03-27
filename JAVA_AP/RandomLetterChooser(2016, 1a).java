import java.io.*;
import java.lang.*;
import java.util.Random;
public class RandomLetterChooser extends RandomStringChooser {
    RandomLetterChooser(String a){
        super(getSingleLetters(a));
    }
    
    public static String[] getSingleLetters(String str){
        String array_2[] = new String[str.length()];
        for(int i = 0; i < str.length(); i ++){
           array_2[i] = str.charAt(i) + "";
        }
      return array_2;
    }

    public static void main(String[] args) {
        RandomLetterChooser letterChooser = new RandomLetterChooser ("cat");
        for(int k = 0; k < 4; k ++){
            System.out.print(letterChooser.getNext());
        }
        System.out.println("");
    }
}