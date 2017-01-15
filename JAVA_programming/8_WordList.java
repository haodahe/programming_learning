import java.util.Scanner;
public class WordList {
   String[] words;
   int count; 
   
   public WordList(){
       String[] array = new String [2]; 
       array[0] = array[1] = "";
       words = array;
       count = 0;
   }
   
   public int addWord(String input){
       int check = findWord(input);
       
       if(check == -1){
           if(this.count != this.words.length){
               this.words[count] = input;
               this.count ++;
               return(this.count);
           }
           else{
               String[] new_words = new String [this.words.length * 2];
               
               for(int ia = 0; ia < this.words.length * 2; ia ++){
                   new_words[ia] = "";
               }
               
               for(int ia = 0; ia < this.count; ia ++){
                   new_words[ia] = this.words[ia];
               }
               this.words = new_words;
               
               this.words[count] = input;
               this.count ++;
               return(this.count);
           }
       }
       return(this.count);
   }
   
   public void removeWord(String input){
       int check = findWord(input);
       
       if(check != -1){
           for(int ia = check; ia < this.count - 1; ia ++){
               this.words[ia] = this.words[ia + 1];
           }
           this.words[count - 1] = "";
           this.count --;
       }
       return;
   }
   
   public int findWord(String input){
       for(int ia = 0; ia < this.count; ia ++){
           if(this.words[ia].equals(input))
               return(ia);
       }
       return(-1);
   }
   
   public boolean equals(WordList input){
       if(this.count == input.count){
           for(int ia = 0; ia < this.count; ia ++){
               //if(this.words[ia].equals(input.words[ia]) == false)
               if(findWord(input.words[ia]) == -1)
                   return(false);
           }
           return(true);
       }
       else
           return(false);
   }
   
   public String toString(){
       String answer;
       
       if(this.count != 1)
           answer = "There are " + count + " words in the word list:\n";
       else
           answer = "There are " + count + " word in the word list:\n";
       
       for(int ia = 0; ia < this.count; ia ++)
           answer = answer + this.words[ia] + "\n";
       
       return answer;
   }

   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); 
       WordList r = new WordList();      
       int number = r.addWord("Haoda");
       number = r.addWord("Haoda");
       WordList t = new WordList();
       boolean answer2 = r.equals(t);
       number = t.addWord("Haoda");      
       System.out.println(answer2);
       
       number = r.addWord("He");
     
       r.removeWord("Haoda");
       //r.removeWord("He");
       String answer = r.toString();
       
       System.out.println(answer);      
       number = r.addWord("Hi");
       number = r.addWord("What are you doing?");         
       number = r.addWord("He");
       number = r.addWord("Haoda");

       
       answer = r.toString();
       
       System.out.println(answer);
   }
}