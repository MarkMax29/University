class Angajat{

private String nume;
private int buget;

    public Angajat(String nume,int buget)
    {
        this.nume=nume;
        this.buget=buget;
    }
    public String returnNume(){

        return nume;
    }
    public int returnBuget(){
        return buget;
    }
}
class Firma{

private String nume_firma;
private int buget,copy_buget;
Angajat[] v=new Angajat[30];
private int index=0;

    public Firma(String nume_firma,int buget)
    {
        this.nume_firma=nume_firma;
        this.buget=buget;
    }

    public boolean adaugaAngajat(Angajat ref){

        if(index>=30)
            return false;
        for(int i=0;i<index;i++)
            {
                if(v[i]==ref)
                    return false;
            }
        v[index]=ref;
        index++;
        return true;
    }

    public String toString()
    {
        String s="";
        s=nume_firma+": ";
        for(int i=0;i<index;i++)
        {
            s=s+"Angajat"+(i+1)+": ("+v[i].returnNume()+", "+v[i].returnBuget()+");";
        }
        return s;
    }
    public int platesteSalarii()
    {
        copy_buget=buget;
        for(int i=0;i<index;i++)
        {
            copy_buget=copy_buget-v[i].returnBuget();
        }
        return copy_buget;
    }
}

class mainAngajati{

    public static void main(String[] argv){

        Firma f=new Firma("Mark's firm",1000);
        Angajat a=new Angajat("Alex",500);
        Angajat b=new Angajat("Levi",300);
        Angajat c=new Angajat("Livi",300);
        System.out.println(f.adaugaAngajat(a));
        System.out.println(f.adaugaAngajat(b));
        System.out.println(f.adaugaAngajat(c));
       // System.out.println(f.adaugaAngajat(b));
       System.out.println(f.toString());
        if(f.platesteSalarii()<0)
            System.out.println("Bugetul care lipseste este: "+f.platesteSalarii());
        else
            System.out.println("Bugetul ramas este: "+f.platesteSalarii());

    }
}

