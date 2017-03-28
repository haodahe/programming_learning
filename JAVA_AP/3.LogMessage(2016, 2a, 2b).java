import java.io.*;
import java.lang.*;
import java.util.Random;
public class LogMessage {
    private String machineId;
    public String description;
    
    public LogMessage(String message){
        for(int i = 0; i < message.length(); i ++)
            if(message.charAt(i) == ':'){
                machineId = message.substring(0, i);
                description = message.substring(i + 1);
            }
    }
    
    public boolean containsWord(String keyword){
        for(int i = 0; i <= description.length() - keyword.length(); i ++){
            if(description.substring(i, i + keyword.length()).equals(keyword)){
                if(i == 0 || description.charAt(i - 1) == ' '){
                    if(i + keyword.length() == description.length() || description.charAt(i + keyword.length()) == ' '){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    //public static void main(String[] args) {
        //LogMessage r = new LogMessage ("SERVER2:read error on disk DSK1");
        
        //System.out.println(r.machineId);
        //System.out.println(r.description);
        //System.out.println(r.containsWord("disk"));
        
    //}
}