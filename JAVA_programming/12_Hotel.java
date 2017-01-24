import java.lang.NullPointerException;
public class Hotel {
    String hotelName;
    Room[] rooms;
    int totalRooms;
   
    Hotel(String hotelName, int totalRooms, int floors){
        this.totalRooms = totalRooms;
        this.hotelName = hotelName;
        rooms = new Room[totalRooms];
        int ia, ib, ic;
        ib = 1;
        ic = 0;
        for(ia = 0; ia < totalRooms; ia ++){
            ic ++;
            if(ic >= (totalRooms / floors) - 4)
                rooms[ia] = new Room((ib * 100) + ic - 1, "single king");
            else
                rooms[ia] = new Room((ib * 100) + ic - 1, "double queen");
            if(ic == (totalRooms / floors))
                rooms[ia] = new Room((ib * 100) + ic - 1, "suite");
            
            System.out.println(rooms[ia].getRoomType() + "   " + rooms[ia].getRoomNumber());
            
            if(ic >= totalRooms / floors){
                ic = 0;
                ib ++;
            }
        }
        
    }
    
    int getTotalRooms(){
        return(this.totalRooms);
    }
   
    int getNumberOccupied (){
        int ia, answer;
        answer = 0;
        for (ia = 0; ia < totalRooms; ia ++){
            if(rooms[ia].getOccupantName() != null){
                answer ++;
            }
        }
        return(answer);
    }
   
    double getOccupancyRate(){
        int ia;
        double answer;
        ia = getNumberOccupied();
        answer = (double)ia / (double)totalRooms;
        answer = answer * 100;
        answer = Math.round(answer);
        answer = answer / 100;
        return(answer);
    }
    
    boolean rentRoom(String roomType, String occupantName, int daysRented){
        int ia;
        for(ia = 0; ia < totalRooms; ia ++){
            if(rooms[ia].getRoomType() == roomType && rooms[ia].getDaysRented() == 0){
                rooms[ia].setOccupant(occupantName, daysRented);
                return(true);
            }
        }
        return(false);
    }
    
    void advanceDay(){
        int ia;
        for(ia = 0; ia < totalRooms; ia ++){
            rooms[ia].advanceDay();
        }
    }
    
    public String toString (){
        double answer = getOccupancyRate();
        answer = answer * 100;
        int answer_2 = (int)answer;
        return(this.hotelName + ": " + answer_2 + "% occupied");
    }
}