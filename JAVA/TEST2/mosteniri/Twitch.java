import java.util.*;

abstract class Utilizator{

    protected String nume;

    public Utilizator(String nume)
    {
        this.nume=nume;
    }
    public abstract double calculeazaVenit(int nr_minute);

}
class Subscriber extends Utilizator{

    private int nivel_subs;

    public Subscriber(String nume,int nivel_subs)
    {
        super(nume);
        this.nivel_subs=nivel_subs;
    }
    public double calculeazaVenit(int nr_minute)
    {
        return nr_minute*1.5*nivel_subs;
    }
    public String toString()
    {
        return nume+" -subscriber- "+nivel_subs;
    }

}
class Creator extends Utilizator{

    private ArrayList<Subscriber> lista;
    public Creator(String nume)
    {
        super(nume);
        lista=new ArrayList<Subscriber>();
    }
    public void adaugaSubscriber(Subscriber s)
    {
        lista.add(s);
    }
    public double calculeazaVenit(int nr_minute)
    {
        double sum=0.0;
        for(Subscriber i:lista)
        {
            sum+=i.calculeazaVenit(nr_minute);
        }
        return sum;
    }

    public String toString()
    {
        String s=nume+" -creator:\n";
        for(Subscriber i:lista)
        {
            s+=i.toString()+"\n";
        }
        return s;

    }
}
class Platforma
{
    private Utilizator[] v;
    private int size;
    public Platforma()
    {
        v=new Utilizator[1000];
        size=0;
    }

    public boolean adaugaUtilizator(Utilizator u)
    {
        if(size<v.length)
        {
            v[size++]=u;
            return true;
        }
        return false;
    }
    public Utilizator determinaVIP(int nr_minute)
    {
        Utilizator aux=null;
        double max=0;
        if(size!=0)
            {
                for(int i=0;i<size;i++)
                {
                    if(max<v[i].calculeazaVenit(nr_minute))
                        {
                            aux=v[i];
                            max=v[i].calculeazaVenit(nr_minute);
                        }
                }
            }
           return aux;
    }

}

class Twitch{
Subscriber s1=new Subscriber("Mara",2);
    public static void main(String[] argv)
    {
        Subscriber s1=new Subscriber("Mara",2);
        Subscriber s2=new Subscriber("Yoyo",5);
        Subscriber s3=new Subscriber("Karla",3);
        Subscriber s4=new Subscriber("Samir",8);
        Subscriber s5=new Subscriber("Dilan",10);
        Subscriber s6=new Subscriber("Marta",7);

        Creator c1=new Creator("Eric Ileanu");
        c1.adaugaSubscriber(s1);
        c1.adaugaSubscriber(s2);
        Creator c2=new Creator("FGTVV");
        c2.adaugaSubscriber(s3);
        c2.adaugaSubscriber(s4);
        c2.adaugaSubscriber(s5);

        Platforma p=new Platforma();
        p.adaugaUtilizator(c1);
        p.adaugaUtilizator(c2);
        p.adaugaUtilizator(s6);

    Utilizator u=p.determinaVIP(30);
       System.out.println(u);
    }
}
