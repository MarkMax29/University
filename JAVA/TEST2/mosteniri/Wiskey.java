import java.util.*;

abstract class Wiskeys{
    protected String nume;
    protected double concentratie;
    public Wiskeys(String nume)
    {
        this.nume=nume;

    }
    public abstract double getNrCalorii(double nr_mililitri);
    public abstract double getConcentratie();

    public String toString()
    {
        return nume+", Concentratie alcool: "+this.getConcentratie()+", Calorii 100ml: "+this.getNrCalorii(100)+" kcal";
    }

}
abstract class Primii2tip extends Wiskeys{

    protected double concentratie;
    public Primii2tip(String nume,double concentratie)
    {
        super(nume);
        this.concentratie=concentratie;
    }

    public double getConcentratie()
    {
        return concentratie;
    }

}
class ClassicWiskey extends Primii2tip{


    public ClassicWiskey(String nume,double concentratie)
    {
        super(nume,concentratie);

    }

    public double getNrCalorii(double nr_mililitri)
    {
        return this.getConcentratie()*nr_mililitri*5;
    }

}

class JackAndHoney extends Primii2tip
{
    private int indulcitor;
    public JackAndHoney(String nume,double concentratie,int indulcitor)
    {
        super(nume,concentratie);
        this.indulcitor=indulcitor;
    }
    public double getNrCalorii(double nr_mililitri)
    {
        return this.getConcentratie()*nr_mililitri*5+indulcitor*nr_mililitri*15;
    }

    public String toString()
    {
        return super.toString()+", Cantitate indulcitor: "+indulcitor;
    }
}
class BlendedWiskey extends Wiskeys{

    private ArrayList<Wiskeys> lista;

    public BlendedWiskey(String nume)
    {
        super(nume);
        lista=new ArrayList<Wiskeys>();
    }
    public void adaugare(Wiskeys w)
    {
        lista.add(w);
    }
    public double getConcentratie()
    {
        double sum=0.0;
        for(Wiskeys i:lista)
        {
            sum+=i.getConcentratie();
        }
        return (double)sum/lista.size();
    }
    public double getNrCalorii(double nr_mililitri)
    {
        double sum=0.0;
        for(Wiskeys i:lista)
        {
            sum+=i.getNrCalorii(nr_mililitri);
        }
        return (double)sum/lista.size();

    }
    public String toString()
    {
        String s=super.toString()+", Compozitie: ";

        for(Wiskeys i:lista)
        {
            s+=i.toString()+"\n";
        }
        return s;
    }
}

class Wiskey{

    public static void main(String[] argv)
    {
        ClassicWiskey cw=new ClassicWiskey("Jack",40);
        JackAndHoney jw=new JackAndHoney("Black Label",50,20);

        ClassicWiskey cw2=new ClassicWiskey("JB",60);
        ClassicWiskey cw3=new ClassicWiskey("GALANTAR",62);

        BlendedWiskey bw=new BlendedWiskey("Corcitura");
        bw.adaugare(cw2);
        bw.adaugare(cw3);


        BlendedWiskey bw2=new BlendedWiskey("Maidanez");
        bw2.adaugare(cw);
        bw2.adaugare(jw);
        bw2.adaugare(bw);

        System.out.println(bw2);

    }


}
