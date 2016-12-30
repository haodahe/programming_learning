import java.util.Scanner;
public class Associative {
  int x;
  int y;
  int z;
  
  Associative(int x, int y, int z){
      this.x = x;
      this.y = y;
      this.z = z;
  }
  
  int firstTwo (){
      int answer;
      answer = this.x + this.y;
      answer *= this.z;
      return answer;
  }
  
  int lastTwo (){
      int answer;
      answer = this.y * this.z;
      answer += this.x;
      return answer;
  }
  
   public static void main(String[] args) {
       Scanner s = new Scanner(System.in); 
       System.out.println("Input x, y, z: ");
       Associative r = new Associative(s.nextInt(), s.nextInt(), s.nextInt());
       
       System.out.println("Grouping the first two terms, (" + r.x + " + " + r.y + ") * " + r.z + " = " + r.firstTwo());
       System.out.println("Grouping the last two terms, " + r.x + " + (" + r.y + " * " + r.z + ") = " + r.lastTwo());
   }
}