class Function{

    public static int minim(int a,int b)
    {
        return a<b? a:b;
    }
}

abstract class Vagon{
    private int pasageri,colete;

    public Vagon(int pasageri,int colete){
        this.pasageri=pasageri;
        this.colete=colete;
    }

    public Vagon(int colete)
    {
        this.colete=colete;
    }

    public int getPasageri()
    {
        return pasageri;
    }

    public int getColete()
    {
        return colete;
    }

    public String toString(){

        if(pasageri!=0)
            return "("+" pasageri:"+pasageri+", colete:"+colete+")\n";
        else
            return "("+"colete:"+colete+")\n";
    }

}

class calatoriA extends Vagon{

    public calatoriA(int pasageri,int colete)
    {
        super(Function.minim(40,pasageri),Function.minim(300,colete));
    }

    public void deschideAuto(){
        System.out.println("Usile sau deschis automat");
    }
    public void inchideAuto(){
        System.out.println("Usile sau inchis automat");

    }
    public String toString(){
        return "calatoriA:"+super.toString();
    }

}
class calatoriB extends Vagon{

    public calatoriB(int pasageri,int colete)
    {
        super(Function.minim(50,pasageri),Function.minim(400,colete));
    }
    public void deschideAuto(){
        System.out.println("Usile sau deschis automat");
    }
    public void inchideAuto(){
        System.out.println("Usile sau inchis automat");

    }
    public void blocare(){
        System.out.println("Geamuri blocate");
    }
    public String toString(){
        return "calatoriB:"+super.toString();
    }


}
class Marfa extends Vagon{

    public Marfa(int colete){
       super(Function.minim(400,colete));

    }
      public String toString(){
        return "Marfa:"+super.toString();
    }

}

class Tren{

    private Vagon []v=new Vagon[15];
    private int size;

    public Tren(Vagon v[])
    {
        this.v=v;
        size=v.length;
    }

    public int nrTotalColete(){

        int sum=0;
        for(int i=0;i<size;i++)
        {
            sum+=v[i].getColete();
        }
        return sum;
    }

    public boolean equals(Object o)
    {
        if(o==null)
            return false;
        if(o instanceof Tren)
        {
            if(((Tren)o).nrTotalColete()==this.nrTotalColete())
                return true;
            return false;
        }
        return false;

    }
    public String toString(){
        String s="Tren:\n";
        for(int i=0;i<size;i++)
        {
            s=s+v[i];
        }
        return s;
    }
}

class prob4_tren{

    public static void main(String []argv){

        Vagon[] v1={
	    new calatoriA(30,120),
	    new calatoriB(45,140),
	    new Marfa(500),//400
	    new calatoriB(60,100)
	};//760
	Vagon[] v2={
	    new Marfa(200),
	    new calatoriB(10,110),
	    new Marfa(270),//400
	    new calatoriA(30,180)
	};//710
	Tren t1=new Tren(v1);
	Tren t2=new Tren(v2);
	System.out.println(t1);
	System.out.println(t2);
    if(t1.equals(t2))
        System.out.println("Sunt egale");
    else
        System.out.println("Nu sunt egale");
    }
}
