import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class TileGame {
   private ArrayList<NumberTile> board;
     
   public TileGame(){
       board = new ArrayList <NumberTile>();
   }
   
   private int getIndexForFit(NumberTile tile){
       for(int i = 0; i < board.size() - 1; i ++){
           if(board.get(i).getRight() == tile.getLeft() && board.get(i + 1).getLeft() == tile.getRight())
               return i;
       }
       return -1;
   }
   
   public boolean insertTile(NumberTile tile){
       int number = getIndexForFit(tile);
       
       if(number == -1 && board.size() == 0)
           board.add(0, tile);
       
       if(number == -1 && board.size() != 0)
           return false;
       else
           board.add(number, tile);
       
       return true;
   }
   
   public static void main(String[] args) {
       TileGame r = new TileGame();
       
       r.board.add(new NumberTile(4, 3, 7, 4));
       r.board.add(new NumberTile(6, 4, 3, 3));
       r.board.add(new NumberTile(1, 2, 3, 4));
       r.board.add(new NumberTile(3, 2, 5, 2));
       r.board.add(new NumberTile(5, 9, 2, 2));
       
       System.out.println(r.insertTile(new NumberTile(4, 2, 9, 8)));
   }
}