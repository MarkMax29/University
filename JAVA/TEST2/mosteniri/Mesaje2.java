import java.util.*;

abstract class Destinatari{

        protected String nume;
        public Destinatari(String nume)
        {
            this.nume=nume;
        }
        public abstract void receptioneaza(Utilizator u,String mesaj);
        public boolean equals(Object o)
        {
            if(o==null)
                return false;
            if(o instanceof Destinatari)
            {
                return (((Destinatari)o).nume==this.nume);
            }
            return false;
        }

}
class Utilizator extends Destinatari{
    private String jurnal;
    public Utilizator(String nume)
    {
        super(nume);
        this.jurnal="";
    }
    public void receptioneaza(Utilizator u,String mesaj)
    {
        jurnal+="Primit de la "+u.nume+" mesajul "+mesaj+"\n";
    }
    public void trimite(Destinatari d,String mesaj)
    {
        this.jurnal+="Trimis catre <"+d.nume+"> mesajul <"+mesaj+">\n";
        d.receptioneaza(this,mesaj);
    }
    public String toString()
    {
        return nume+":"+jurnal;
    }
}
class DestinatarDuplicat extends Exception
{
    public DestinatarDuplicat()
    {
        super("SE AFLA DEJA IN LISTA!");
    }
}
class Grup extends Destinatari
{
    private ArrayList<Destinatari> lista;
    public Grup(String nume)
    {
        super(nume);
        lista=new ArrayList<Destinatari>();
    }
    public void inscrie(Destinatari d) throws DestinatarDuplicat
    {
        for(Destinatari i:lista)
        {
            if(i.equals(d)==true)
                    throw new DestinatarDuplicat();


        }
        lista.add(d);
    }
    public void receptioneaza(Utilizator u,String mesaj)
    {
        for(Destinatari i:lista)
        {
            if(i.equals(u)==false)
                i.receptioneaza(u,mesaj);
        }
    }
}
class Mesaje2
{
    public static void main(String[] argv)
    {
        Utilizator u1=new Utilizator("Dan");
        Utilizator u2=new Utilizator("Marius");
        Utilizator u3=new Utilizator("Alex");
        Grup g=new Grup("Carnivorii");
        try{g.inscrie(u1);
        }catch(DestinatarDuplicat e)
        {
            System.out.println(e.getMessage());
        }
          try{g.inscrie(u2);
        }catch(DestinatarDuplicat e)
        {
            System.out.println(e.getMessage());
        }
          try{g.inscrie(u3);
        }catch(DestinatarDuplicat e)
        {
            System.out.println(e.getMessage());
        }
          try{g.inscrie(u2);
        }catch(DestinatarDuplicat e)
        {
            System.out.println(e.getMessage());
        }

        u3.trimite(g,"Am deschis magazinul");
        u2.trimite(g,"Vin acuma");

        System.out.println(u1);
        //System.out.println(u2);
        //System.out.println(u3);


    }
}

