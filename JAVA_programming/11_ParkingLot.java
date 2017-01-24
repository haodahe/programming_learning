public class ParkingLot{
    ParkingSpace[] parkingLot;
    int numSpaces;
    int numFloors;
    
    public ParkingLot(int numSpaces, int numFloors){
        this.numSpaces = numSpaces;
        this.numFloors = numFloors;
        parkingLot = new ParkingSpace[this.numSpaces * this.numFloors];
        int number, ia, ib;
        number = 0;
        for(ia = 0; ia < numFloors; ia ++){
            for(ib = 0; ib < numSpaces; ib ++){
                if(ib < 4)
                    parkingLot[number] = new ParkingSpace(ib, (char)(ia + 'A'), true);
                else
                    parkingLot[number] = new ParkingSpace(ib, (char)(ia + 'A'), false);
                number++;
            }
        }
    }
    
    public ParkingSpace enterLot(boolean check){
        int ia;
        for(ia = 0; ia < parkingLot.length; ia ++){
            if(check == true){
                if(parkingLot[ia].getOccupied() == false){
                    parkingLot[ia].setOccupied(true);
                    return parkingLot[ia];
                }
            }
            else
                if(parkingLot[ia].getOccupied() == false && parkingLot[ia].getCompact() == false){
                    parkingLot[ia].setOccupied(true);
                    return parkingLot[ia];
                }
        }
        return null;
    }
    
    public void leaveLot(ParkingSpace number){
        int number2 = (number.getFloor() - 'A') * numSpaces + number.spaceNum;
        parkingLot[number2].setOccupied(false);
    }
}