import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class MusicDownload {
   public List <Downloadinfo> downloadList;
   
   MusicDownload(){
       downloadList = new ArrayList<Downloadinfo>();
   }
   
   public Downloadinfo getDownloadInfo(String title){
       for(int i = 0; i < downloadList.size(); i ++){
           if(downloadList.get(i).getTitle().equals(title)){
               return downloadList.get(i);
           }
       }
       return downloadList.get(0);
   }
   
   public void updateDownload(List<String> titles){
       for(int i = 0; i < titles.size(); i ++){
           int number = 0;
           for(int j = 0; j < downloadList.size(); j ++){
               if(titles.get(i).equals(downloadList.get(j).getTitle())){
                   downloadList.get(j).incrementTimesDownload();
                   number = 1;
                   break;
               }
           }
           if(number == 0){
               Downloadinfo download = new Downloadinfo(titles.get(i));
               download.incrementTimesDownload();
               
               downloadList.add(download);
           }
       }
   }
   
   public static void main(String[] args) {
       MusicDownload r = new MusicDownload();
       
       List <String> songTitles = new ArrayList <String>();
       songTitles.add("Lights");
       songTitles.add("Aqualung");
       songTitles.add("Soul Sister");
       songTitles.add("Go Now");
       songTitles.add("Lights");
       songTitles.add("Soul Sister");
       
       r.updateDownload(songTitles);
       
       for(int i = 0; i < r.downloadList.size(); i ++){
           System.out.print(r.downloadList.get(i).getTitle() + ",");
       }
   }
}