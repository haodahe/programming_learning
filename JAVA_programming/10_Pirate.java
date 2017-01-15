import java.util.Random;
public class Pirate {
    String name;
    int health, swordsmanship, agility;
    boolean hasParrot, hasPegLeg;
    int doubloons;
    static int numberOfPirates = 0;
        
    Pirate(String name, int swordsmanship, int agility, boolean hasParrot, boolean hasPegLeg){
        this.name = name;
        this.swordsmanship = swordsmanship;
        this.agility = agility;
        this.hasParrot = hasParrot;
        this.hasPegLeg = hasPegLeg;
        this.health = 10;
        this.doubloons = 25;
        numberOfPirates ++;
    }
    
    Pirate(String name){
        this.health = 10;
        this.doubloons = 25;
        Random rand = new Random();
        this.name = name;
        this.swordsmanship = rand.nextInt(10);
        this.agility = rand.nextInt(10);
        
        if(rand.nextDouble() < 0.25)
            hasParrot = true;
        else
            hasParrot = false;
        numberOfPirates ++;
    }
    
    String swashbuckle(Pirate t){
        Random rand = new Random();
        int randInt = rand.nextInt(20);
        if((t.hasPegLeg == true && (t.agility - 1) > randInt) || (t.hasPegLeg == false && t.agility > randInt)){
            return (t.name + " dodged yar attack!");
        }
        int number;
        if(this.hasParrot == true)
            number = rand.nextInt(swordsmanship + 1);
        else
            number = rand.nextInt(swordsmanship);
        
        t.health -= number;
        if(t.health <= 0){
            t.health = 0;
            this.doubloons += t.doubloons;
            t.doubloons = 0;
            numberOfPirates --;
        }
        return (this.name + " swabs the deck with " + t.name + " for " + number);
    }
    
    boolean isNapping(){
        if(this.health == 0)
            return true;
        else
            return false;
    }
    
    public String toString(){
        String answer;
        if(this.hasParrot == true && this.hasPegLeg == true){
            return(answer = this.name + " (H: " + this.health + ", S: " + this.swordsmanship + ", A: " + this.agility + ", $" + this.doubloons + ")\nThis pirate has a parrot and has a pegleg.");
        }
        else if(this.hasParrot == false && this.hasPegLeg == true){
            return (answer = this.name + " (H: " + this.health + ", S: " + this.swordsmanship + ", A: " + this.agility + ", $" + this.doubloons + ")\nThis pirate does not have a parrot and has a pegleg.");
        }
        else if(this.hasParrot == true && this.hasPegLeg == false){
            return (answer = this.name + " (H: " + this.health + ", S: " + this.swordsmanship + ", A: " + this.agility + ", $" + this.doubloons + ")\nThis pirate has a parrot and does not have a pegleg.");
        }
        else{
            return (answer = this.name + " (H: " + this.health + ", S: " + this.swordsmanship + ", A: " + this.agility + ", $" + this.doubloons + ")\nThis pirate does not have a parrot and does not have a pegleg.");
        }
    }
    
    public static void main(String[] args) {
    }
}