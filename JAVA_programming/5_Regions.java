import java.util.Scanner;
public class Regions {
    Regions(){
    }
    
    static String getRegion(String input){
        switch (input){
            case "ME" : case "VT" : case "NH" : case "MA" : case "CT" : case "RI" :
                return "New England";
            case "NY" : case "NJ" : case "DE" : case "MD" : case "VA" : case "NC" : case "SC" :
                return "Atlantic";
            case "GA" : case "FL" : case "MS" : case "AL" : case "LA" : case "TN" :
                return "Southeast";
            case "PA" : case "OH" : case "MI" : case "IN" : case "IL" : case "WI" : case "MN" : case "KY" : case "WV" : case "IA" :
                return "Midwest";
            case "ND" : case "SD" : case "KS" : case "NE" : case "MO" : 
                return "Great Plains";
            default :
                return "invalid input";
        }
    }
  
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in); 
        System.out.println("input a state by two-letter abbreviation: ");
        Regions r = new Regions();
        String input = s.nextLine();
        
        String answer = r.getRegion(input);
        if(answer != "invalid input")
            System.out.println("The state " + input + " is in the " + answer + " region");
        else
            System.out.println("This is an invalid state abbreviation");
     
    }
}