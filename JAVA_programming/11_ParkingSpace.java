public class ParkingSpace{
   int spaceNum;
   char floor;
   boolean isCompact, isOccupied;
   
   ParkingSpace(int spaceNum, char floor, boolean isCompact){
       this.spaceNum = spaceNum;
       this.floor = floor;
       this.isCompact = isCompact;
       this.isOccupied = false;
   }
   
   public int getSpaceNum(){
       return (spaceNum);
   }
   
   public char getFloor(){
       return (floor);
   }
   
   public boolean getCompact(){
       return (isCompact);
   }
   
   public boolean getOccupied(){
       return (isOccupied);
   }
   
   public void setOccupied(boolean isOccupied){
       this.isOccupied = isOccupied;
   }
   
   public String toString(){
       char ia, ib;
       if(this.isCompact == true)
           ia = 'C';
       else
           ia = 'N';
       if(this.isOccupied == true)
           ib = 'X';
       else
           ib = 'O';
       return(this.floor + "" + this.spaceNum + " (" + ia + " " + ib + ")");
   }
   /*
   public static void main(String[] args) {
       ParkingSpace r = new ParkingSpace(5, 'A', false);
       
       String answer = r.toString();
       System.out.println(answer);
   }
   */
}