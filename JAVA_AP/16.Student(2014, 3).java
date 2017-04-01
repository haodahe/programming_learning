import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class Student{
   private String name;
   private int absence;
   Student(String name, int absence){
       this.name = name;
       this.absence = absence;
   }
   
   public String getName(){
       return name;
   }
   
   public int getAbsenceCount(){
       return absence;
   }
}