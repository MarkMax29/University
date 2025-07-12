abstract class Avion{
private String planeID;
private int totalEnginePower;

    public Avion(String planeID,int totalEnginePower){
        this.planeID=planeID;
        this.totalEnginePower=totalEnginePower;
    }
    public String getPlaneID(){
        return planeID;
    }
    public int getTotalPower(){
        return totalEnginePower;
    }
    public void takeOff(){
        System.out.println(this.getPlaneID()+"- Initiating takeoff procedure - Starting engines - Accelerating down the runway - Taking off - Retracting gear - Takeooff complete");
    }
    public void fly(){
        System.out.println(this.getPlaneID()+"- Flying");
    }
    public void land(){
         System.out.println(this.getPlaneID()+"- Initiating landing procedure - Enabling airbrakes - Lowering gear - Contacting runway - Decelerating - Stopping engines - Landing complete");
    }

}

abstract class AvioanedeCalatori extends Avion{
    private int maxPassengers;
    public AvioanedeCalatori(String planeID,int totalEnginePower,int maxPassengers)
    {
        super(planeID,totalEnginePower);
        this.maxPassengers=maxPassengers;
    }

    public int getMaxPassengers(){
        return maxPassengers;
    }
}

class Concorde extends AvioanedeCalatori{

    public Concorde(String planeID,int totalEnginePower,int maxPassengers)
    {
        super(planeID,totalEnginePower,maxPassengers);
    }

    public void goSuperSonic(){
        System.out.println(this.getPlaneID()+"- Supersonic mode activated");
    }
    public void goSubSonic(){
        System.out.println(this.getPlaneID()+"- Supersonic mode deactivated");
    }
}
class Boeing extends AvioanedeCalatori{
    public Boeing(String planeID,int totalEnginePower,int maxPassengers)
    {
        super(planeID,totalEnginePower,maxPassengers);
    }
}
abstract class AvioaneDeLupta extends Avion{

    public AvioaneDeLupta(String planeID,int totalEnginePower)
    {
        super(planeID,totalEnginePower);
    }

    public void launchMissle(){
        System.out.println(this.getPlaneID()+"- Initiating missile launch procedure - Acquiring target - Launching missile - Breaking away - Missile launch complete");
    }
}

class Mig extends AvioaneDeLupta{

    public Mig(String planeID,int totalEnginePower){
        super(planeID,totalEnginePower);
    }
    public void highSpeedGeometry(){
        System.out.println(this.getPlaneID()+"- High speed geometry selected");
    }
    public void normalGeometry(){
        System.out.println(this.getPlaneID()+"- Normal geometry selected");
    }

}

class TomCat extends AvioaneDeLupta{

    public TomCat(String planeID,int totalEnginePower){
        super(planeID,totalEnginePower);
    }
    public void refuel(){
        System.out.println(this.getPlaneID()+"- Initiating refueling procedure - Locating refueller - Catching up -Refueling - Refueling complete");
    }
}

class lab7{

    public static void main(String[] argv){

        Avion boeing=new Boeing("Boeing1",5000,120);
        if(boeing instanceof Boeing)
        {
            boeing.takeOff();
            boeing.fly();
            boeing.land();
        }

        Avion concorde=new Concorde("Concorde 1",6000,80);
        if(concorde instanceof Concorde)
        {
            ((Concorde)concorde).goSuperSonic();
            ((Concorde)concorde).goSubSonic();

        }
        Avion mig=new Mig("Mig1",25000);
        if(mig instanceof Mig)
        {
            ((Mig)mig).highSpeedGeometry();
        }
        Avion tomcat=new TomCat("TomCat1",36000);
        if(tomcat instanceof TomCat)
        {
            ((TomCat)tomcat).refuel();
        }
    }
}
