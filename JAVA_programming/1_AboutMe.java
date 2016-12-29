import java.util.Scanner;
public class AboutMe {
   int age;
   String name, school;
   
   AboutMe(String name, String school, int age){
       this.name = name;
       this.school = school;
       this.age = age;
   }
   
   String myName() {
       return this.name;
   }
   String mySchool() {
       return this.school;
   }
   int myAge() {
       return this.age;
   }
   
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); 
       AboutMe r = new AboutMe(s.nextLine(), s.nextLine(), s.nextInt());
       
       System.out.println("Hello!");
       System.out.println("My name is " + r.myName() + ", and I attend " + r.mySchool() + ". I am " + r.myAge() + " years old.");
   }
}


