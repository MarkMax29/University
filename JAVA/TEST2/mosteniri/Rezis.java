import java.util.*;
abstract class CircuitElectric{

    public abstract double rezistentaEchivalenta();
    public double curent(double tensiune)
    {
        return tensiune/rezistentaEchivalenta();
    }
    public abstract boolean contineSubcircuit(CircuitElectric subcircuit);

}

class Rezistenta extends CircuitElectric{

    private double val;

    public Rezistenta(double val)
    {
        this.val=val;
    }
    public double rezistentaEchivalenta()
    {
        return val;
    }
    public boolean contineSubcircuit(CircuitElectric subcircuit)
    {
        if(this==subcircuit)
            return true;
        return false;
    }
}

abstract class CircuitCompus extends CircuitElectric{

    protected ArrayList<CircuitElectric> lista;
    public CircuitCompus(ArrayList<CircuitElectric> lista)
    {
        this.lista=lista;// o setez si primesc ca parametru deja lista cu elementele introduse
        //lista=new ArrayList<CircuitElectric>();//asta inseamna ca o creez in constructor si as fi avut nevoie de o metoda de adaugare

    }
    public boolean contineSubcircuit(CircuitElectric subcircuit)
    {
        for(CircuitElectric i:lista)
        {
            if(i.contineSubcircuit(subcircuit)==true)
                return true;
        }
        return false;
    }

}

class CircuitSerie extends CircuitCompus{

    public CircuitSerie(ArrayList<CircuitElectric> lista)
    {
        super(lista);
    }
    public double rezistentaEchivalenta(){

        double sum=0;
        for(CircuitElectric i:lista)
        {
            sum+=i.rezistentaEchivalenta();
        }
        return sum;
    }

}
class CircuitParalel extends CircuitCompus{

    public CircuitParalel(ArrayList<CircuitElectric> lista)
    {
        super(lista);
    }
    public double rezistentaEchivalenta(){

        double sum=0;
        for(CircuitElectric i:lista)
        {
            sum+=1/i.rezistentaEchivalenta();
        }

        return 1/sum;
    }

}

class Rezis{
    public static void main(String[] argv)
    {
        Rezistenta r1=new Rezistenta(2);
        Rezistenta r2=new Rezistenta(1);
        Rezistenta r3=new Rezistenta(4);
        Rezistenta r4=new Rezistenta(2);

        ArrayList<CircuitElectric> l1=new ArrayList<CircuitElectric>();
        l1.add(r1);
        l1.add(r2);
         ArrayList<CircuitElectric> l2=new ArrayList<CircuitElectric>();
        l2.add(r3);l2.add(r4);
        CircuitSerie s1=new CircuitSerie(l1);
        CircuitSerie s2=new CircuitSerie(l2);
        ArrayList<CircuitElectric> l3=new ArrayList<CircuitElectric>();
        l3.add(s1);
        l3.add(s2);

        CircuitParalel p=new CircuitParalel(l3);
        System.out.println(p.rezistentaEchivalenta());
        System.out.println(p.curent(9));
        System.out.println(p.contineSubcircuit(r1));


    }
}
