import java.util.Scanner;
public class Alphabet {
    Alphabet(){
    }
    
    static String whatsMissing(String input){
        int ic;
        char letter = 'a';
        String answer = "";
        
        for(int ia = 0; ia < 26; ia ++){
            ic = 0;
            for(int ib = 0; ib < input.length(); ib ++){
              if(input.charAt(ib) == letter){
                  ic = 1;
                  break;
              }
            }
            if(ic == 0)
                answer = answer + letter;
            
            letter ++;
        }
        
        return(answer);
    }
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in); 
        System.out.println("input a sentence: ");
        Alphabet r = new Alphabet();
        
        String answer = r.whatsMissing(s.nextLine());
        
        System.out.println("The missing letters are: " + answer + ".");
    }
}