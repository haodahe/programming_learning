import java.lang.NullPointerException;
public class Room {
   public int roomNumber, daysRented;
   public String roomType, occupantName;
   
   Room(int roomNumber, String roomType){
       this.roomNumber = roomNumber;
       this.daysRented = 0;
       this.occupantName = null;
       
       if(roomType == "single king" || roomType == "double queen" || roomType == "suite")
           this.roomType = roomType;
       else
           this.roomType = "double queen";
   }
   
   int getRoomNumber (){
       return(roomNumber);
   }
   
   int getDaysRented (){
       return(daysRented);
   }
   
   String getRoomType (){
       return(roomType);
   }
   
   String getOccupantName (){
       return(occupantName);
   }
   
   boolean setOccupant (String occupantName, int daysRented){
       if(this.daysRented == 0){
           this.daysRented = daysRented;
           this.occupantName = occupantName;
           return(true);
       }
       return (false);
   }
   
   void advanceDay (){
       this.daysRented--;
       if(this.daysRented <= 0){
           this.daysRented = 0;
           this.occupantName = null;
       }
   }
   
   public String toString (){
       String answer = "Room " + this.roomNumber + ": " + this.roomType + " - ";
       if(this.daysRented == 0)
           answer = answer + "free";
       else
           answer = answer + "rented";
       return(answer);
   }
}