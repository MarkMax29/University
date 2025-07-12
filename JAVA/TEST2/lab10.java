import java.util.Random;
import java.util.Date;
class CoordinateGenerator {
private Random randomGenerator;

public CoordinateGenerator() {
    Date now = new Date();
    long sec = now.getTime();
    randomGenerator = new Random(sec);
}

public int generateX() {
    int x = randomGenerator.nextInt(101);
    if(x < 5) {
        x = 0;}
    else if(x > 95) {
        x = 100;}
    else {
        x = randomGenerator.nextInt(99) + 1;
    }

    return x;
}

public int generateY() {
    int y = randomGenerator.nextInt(101);
    if(y < 5) {
        y = 0;}
    else if(y > 95) {
        y = 50;}
    else {
        y = randomGenerator.nextInt(49) + 1;
    }

    return y;
}
}

class Out extends Exception{}
class Gol extends Exception{}
class Corner extends Exception{}

class Minge{
    private int x,y;
    private CoordinateGenerator rand=new CoordinateGenerator();

    public Minge(int x,int y)
    {
        this.x=x;
        this.y=y;
    }
    public int getX(){
        return x;
    }

    public int getY(){
        return y;
    }
    public void suteaza() throws Out,Gol,Corner{
        x=rand.generateX();
        y=rand.generateY();

        if(y==0 || y==50)
            throw new Out();
        else if((x==0 || x==100 ) && y>=20 && y<=30)
            throw new Gol();
        else if((x==0 || x==100) && ((0<y && y<20)||(30<y && y<50)))
            throw new Corner();

        }

    public String toString(){

        return "("+x+","+y+")";
    }
    }

class Joc{
    private String echipa1,echipa2;
    private int gol1,out1,corner1;
    private int gol2,out2,corner2;

    public Joc(String echipa1,String echipa2)
    {
        this.echipa1=echipa1;
        this.echipa2=echipa2;
    }
       public String toString(){
        String s=echipa1+" Goluri:"+gol1+" Outuri:"+out1+" Corner: "+corner1+"\n";
        s=s+echipa2+" Goluri:"+gol2+" Outuri:"+out2+" Corner: "+corner2;
        return s;
    }

    public String poz(Minge m){
        return echipa1+ " - "+echipa2+" Mingea se afla la pozitia : "+m.toString();
    }
    public void simuleaza()
    {
        Minge m=new Minge(50,25);

        for(int i=0;i<1000;i++)
        {
            try{
                m.suteaza();
            }
            catch(Gol e)
            {
                if(m.getX()==0)
                    gol1++;
                else if(m.getX()==100)
                    gol2++;
                m=new Minge(50,25);
            }
            catch(Out e)
            {
                if(m.getY()==0)
                    out1++;
                else if(m.getY()==50)
                    out2++;
                m=new Minge(m.getX(),m.getY());
            }
              catch(Corner e)
            {
                if(m.getX()==0)
                    {
                    if(m.getY()>0 && m.getY()<20)
                      {
                         corner1++;
                         m=new Minge(0,0);
                      }
                    else if(m.getY()>30 && m.getY()<50)
                        {
                         corner1++;
                         m=new Minge(0,50);
                        }
                    }
                else if(m.getX()==100)
                {
                  if(m.getY()>0 && m.getY()<20)
                   {
                    corner2++;
                    m=new Minge(100,0);
                   }
                else if(m.getY()>30 && m.getY()<50)
                   {
                    corner2++;
                    m=new Minge(100,50);
                    }
                }
        }

        finally{
            System.out.println(poz(m));
        }
        System.out.println(toString());
    }

}
}
 class lab10{
        public static void main(String[] argv)
        {
            Joc j=new Joc("Levi","Erik");
            j.simuleaza();
        }
    }


