import java.util.*;

abstract class Proprietati{
private String strada;
private int nr,suprafata;

    public Proprietati(String strada,int nr,int suprafata)
    {
        this.strada=strada;
        this.nr=nr;
        this.suprafata=suprafata;
    }
   public abstract double cost();


    public int getSuprafata() {
        return suprafata;
    }
   public String toString(){
    return "Adresa: "+strada+" Nr."+nr+", Suprafata:"+suprafata;
   }

}

class Cladire extends Proprietati{

    private String strada_clad;
    private int nr_clad,suprafata;

    public Cladire(String strada_clad,int nr_clad,int suprafata){
        super(strada_clad,nr_clad,suprafata);
    }

    public double cost(){
        return 500*getSuprafata();
    }
    public String toString(){
    return "Cladire: "+super.toString()+", cost:"+this.cost();
   }
}
class Teren extends Proprietati{

    private String strada_teren;
    private int nr_teren,suprafata,rang;
    public Teren(String strada_teren,int nr_teren,int suprafata,int rang){
        super(strada_teren,nr_teren,suprafata);//trebe ca apelul cu super sa fie prima in constructor mereu!!!
        this.rang=rang;

    }
    public double cost(){
        return (350*getSuprafata())/rang;
    }
     public String toString(){
    return "Teren: "+super.toString()+", Rang:"+rang+", Cost:"+this.cost();
   }
}

class Contribuabil{
    private String nume;
    private List<Proprietati> lista_proprietati;
    public Contribuabil(String nume)
    {
        this.nume=nume;
        this.lista_proprietati=new ArrayList<>();//
    }

    public void adaugainLista(Proprietati prop){
        lista_proprietati.add(prop);
    }

    public double calculSumaTotala(){
        double suma = 0;
        for (Proprietati p : lista_proprietati)
        {
            suma += p.cost();
        }
    return suma;
    }

    public void afisFluturas(){
        System.out.println("Contribuabil: "+nume);
        for(Proprietati p:lista_proprietati)
        {
            System.out.println(p);
        }
        System.out.println("Suma totala: "+calculSumaTotala());
    }
/*
    public String getNume(){
        return nume;
    }
*/

}

class lab8{

    public static void main(String []argv)
    {
        Contribuabil c1=new Contribuabil("Ion Popescu");

        c1.adaugainLista(new Cladire("Strada V.Parvan",2,20));
        c1.adaugainLista(new Teren("Strada V.Parvan",2,10,1));
        c1.adaugainLista(new Cladire("Strada Lugoj",4,25));


        c1.afisFluturas();
    }
}
