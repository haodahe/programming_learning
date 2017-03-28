import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class SystemLog {
    private List<LogMessage> messageList;
    private List<LogMessage> messageList2;
    
    SystemLog(){
        messageList = new ArrayList<LogMessage>();
        messageList2 = new ArrayList<LogMessage>();
    }
    
    public List removeMessages(String keyword){       
        for(int i = 0; i < messageList.size(); i ++){
            if(messageList.get(i).containsWord(keyword)){
                messageList2.add(messageList.get(i));
                messageList.remove(i);
                i --;
            }
        }
        return messageList2;
    }

    public static void main(String[] args) {
        SystemLog r = new SystemLog ();
        
        LogMessage a1 = new LogMessage("CLIENT3:security alert - repeated login failures");
        LogMessage a2 = new LogMessage("Webserver:disk offline");
        LogMessage a3 = new LogMessage("SERVER1:file not found");
        LogMessage a4 = new LogMessage("SERVER2:read error on disk DSK1");
        LogMessage a5 = new LogMessage("SERVER1:write error on disk DSK2");
        LogMessage a6 = new LogMessage("Webserver:error on /dev/disk");
        
        r.messageList.add(a1);
        r.messageList.add(a2);
        r.messageList.add(a3);
        r.messageList.add(a4);
        r.messageList.add(a5);
        r.messageList.add(a6);
        
        r.messageList2 = r.removeMessages("disk");
        
        for(int i = 0; i < 6; i ++)
            System.out.println(r.messageList.get(i).description);
    }
}
