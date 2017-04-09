import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class NumberCube {
   NumberCube(){
   }
   
   public int toss(){
       Random randomGenerator = new Random();
       return randomGenerator.nextInt(6) + 1;
   }
}