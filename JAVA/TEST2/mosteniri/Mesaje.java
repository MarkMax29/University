import java.util.*;

abstract class Destinatar{
    protected String nume;

    public Destinatar(String nume)
    {
        this.nume=nume;
    }

    abstract public void receptioneaza(Utilizator u,String nume);

    public boolean equals(Object o)
    {
        if(o==null)
            return false;
        if(o instanceof Destinatar)
        {
            return (((Destinatar)o).nume==this.nume);
        }
        return false;
    }

}
class Utilizator extends Destinatar{

    private String jurnal;
    public Utilizator(String nume)
    {
        super(nume);
        jurnal="";
    }
    public void trimite(Destinatar d,String mesaj)
    {
        this.jurnal+="Trimis catre:"+d.nume+" mesajul:"+mesaj+"\n";
        d.receptioneaza(this,mesaj);
    }
    public void receptioneaza(Utilizator u,String mesaj)
    {
        jurnal+="Primit de la "+u.nume+" mesajul:"+mesaj+"\n";
    }
    public String toString()
    {
        return "Nume utilizator :"+nume+" "+jurnal;
    }
}

class DestinatarDublicat extends Exception{
    public DestinatarDublicat()
    {
        super("SE AFLA DEJA!");
    }
}
class Grup extends Destinatar{
    private ArrayList<Destinatar> lista;
    public Grup(String nume)
    {
        super(nume);
        lista=new ArrayList<Destinatar>();
    }

    public void inscrie(Destinatar d) throws DestinatarDublicat
    {
        for(Destinatar i:lista)
        {
            if(i.equals(d)==true)
               throw new DestinatarDublicat();
        }
        lista.add(d);

    }

    public void receptioneaza(Utilizator u,String mesaj)
    {
        for(Destinatar d:lista)
        {
            if(d.equals(u)==false)
                d.receptioneaza(u,mesaj);
        }

    }

}

class Mesaje{
    public static void main(String [] argv)
    {
        Utilizator u1=new Utilizator("Dan");
        Utilizator u2=new Utilizator("Marius");
        Utilizator u3=new Utilizator("Alex");
        Grup g=new Grup("Carnivorii");


        try{
            g.inscrie(u1);

        }catch(DestinatarDublicat e){
        System.out.println(e.getMessage());
        }
        try{
            g.inscrie(u2);

        }catch(DestinatarDublicat e){
        System.out.println(e.getMessage());
        }
        try{
            g.inscrie(u3);

        }catch(DestinatarDublicat e){
        System.out.println(e.getMessage());
        }
        try{
            g.inscrie(u2);

        }catch(DestinatarDublicat e){
        System.out.println(e.getMessage());
        }

        u3.trimite(g,"Am deschis magazinul");
        u2.trimite(g,"Vin acuma");

        System.out.println(u1.toString());
        System.out.println(u2.toString());
        System.out.println(u3.toString());

    }
}
