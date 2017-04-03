import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class Downloadinfo {
   String title;
   int download;
     
   Downloadinfo(String title){
       this.title = title;
   }
   
   public String getTitle(){
       return title;
   }
   
   public void incrementTimesDownload(){
       download ++;
   }
}