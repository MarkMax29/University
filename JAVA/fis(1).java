class Fisier{
    public int id;
    private static int k=0;
    private Fisier prev=null;
    private int nrc=0;
    String nume,continut;

    Fisier(String nume,String continut){
    this.nume=nume;
    this.continut=continut;
    id=k;
    k++;
    }
    public void Print(Fisier a){
        System.out.print(a.id+" "+a.nume+" "+a.continut+" ");
        if(a.prev!=null)
            System.out.println(a.prev.nume);
        else
            System.out.println("NIMIC NOU");

    }
    public void  salveazaVersiune(Fisier a)
    {
        Fisier o=new Fisier(a.nume,a.continut);
        o.nume=o.nume+".bak";
        o.id=a.id;
        o.prev=this.prev;
        this.prev=o;
    }

    public void concatenare(Fisier a)
    {
    salveazaVersiune(this);
    this.continut=this.continut+" "+a.continut;
    nrc++;

    }
    public int numarConcatenari()
    {
        return nrc;
    }

}

class fis{

public static void main(String argv[])
{
Fisier a=new Fisier("ceva","yes");
Fisier b=new Fisier("ceva","no");
Fisier c=new Fisier("ceva","altcv");
Fisier d=new Fisier("ceva","nush");
a.Print(a);
b.Print(b);
c.Print(c);
d.Print(d);
b.salveazaVersiune(b);
b.concatenare(a);
b.concatenare(a);
b.concatenare(a);
b.concatenare(a);

b.Print(b);
System.out.println(b.numarConcatenari());
/*c.salveazaVersiune(c);


c.Print(c);*/
}
}
