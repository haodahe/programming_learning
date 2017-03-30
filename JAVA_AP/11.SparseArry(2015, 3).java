import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class SparseArry {
   private int numRows;
   private int numCols;
   private List<SparseArrayEntry> entries;
   
   public SparseArry(){
       entries = new ArrayList<SparseArrayEntry>();
   }
   
   public int getNumRows(){
       return numRows;
   }
   
   public int getNumCols(){
       return numCols;
   }
   
   public int getValueAt(int row, int col){
       int answer = 0;
       for(int i = 0; i < entries.size(); i ++){
           if(entries.get(i).getRow() == row && entries.get(i).getCol() == col){
               return entries.get(i).getValue();
           }
       }
       return answer;
   }
   
   public void removeColumn(int col){
       for(int i = 0; i < entries.size(); i ++){
           if(entries.get(i).getCol() == col){
               entries.remove(i);
               i --;
           }
       }
   }
   
   public static void main(String[] args) {
       SparseArry r = new SparseArry();
       
       SparseArrayEntry a = new SparseArrayEntry(1, 4, 4);
       SparseArrayEntry b = new SparseArrayEntry(2, 0, 1);
       SparseArrayEntry c = new SparseArrayEntry(3, 1, -9);
       SparseArrayEntry d = new SparseArrayEntry(1, 1, 5);
       
       r.entries.add(a);
       r.entries.add(b);
       r.entries.add(c);
       r.entries.add(d);
       
       r.removeColumn(1);
       
       System.out.println(r.getValueAt(1, 1));
   }
}