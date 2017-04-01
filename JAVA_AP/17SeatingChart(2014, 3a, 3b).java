import java.io.*;
import java.lang.*;
import java.util.Random;
import java.util.*;
public class SeatingChart{
   private Student[][] seats;
   SeatingChart(List <Student> studentList, int rows, int coles){
       seats = new Student[rows][coles];
       for(int i = 0; i < rows; i ++)
           for(int j = 0; j < coles; j ++)
               seats[i][j] = null;
       
       int number = 0;
       
       for(int j = 0; j < coles; j ++)
           for(int i = 0; i < rows; i ++){
               if(number == studentList.size())
                   break;
               
               seats[i][j] = studentList.get(number);
               number ++;
           }
   }   
   
   public int removeAbsentStudents(int allowedAbsences){
       int number = 0;
       for(int i = 0; i < seats.length; i ++){
           for(int j = 0; j < seats[0].length; j ++)
               if(seats[i][j] != null && seats[i][j].getAbsenceCount() > allowedAbsences){
                   seats[i][j] = null;
                   number ++;
               }
       }
       return number;
   }
   
   public static void main(String[] args) {
       Student a = new Student("Karen", 3);
       Student b = new Student("Liz", 1);
       Student c = new Student("Paul", 4);
       Student d = new Student("Lester", 1);
       Student e = new Student("Henry", 5);
       Student f = new Student("Renee", 9);
       Student g = new Student("Glen", 2);
       Student h = new Student("Fran", 6);
       Student i = new Student("David", 1);
       Student j = new Student("Danny", 3);
       
       List <Student> list = new ArrayList<Student>();
       
       list.add(a);
       list.add(b);
       list.add(c);
       list.add(d);
       list.add(e);
       list.add(f);
       list.add(g);
       list.add(h);
       list.add(i);
       list.add(j);
       
       SeatingChart r = new SeatingChart(list, 3, 4);
       
       for(int ia = 0; ia < 3; ia ++){
           for(int ja = 0; ja < 4; ja ++)
               if(r.seats[ia][ja] != null)
                   System.out.print(r.seats[ia][ja].getName() + " ");
           System.out.println("");
       }
       
       System.out.println("");
       int number = r.removeAbsentStudents(4);
       
       for(int ia = 0; ia < 3; ia ++){
           for(int ja = 0; ja < 4; ja ++)
               if(r.seats[ia][ja] != null)
                   System.out.print(r.seats[ia][ja].getName() + " ");
           System.out.println("");
       }
   }
}