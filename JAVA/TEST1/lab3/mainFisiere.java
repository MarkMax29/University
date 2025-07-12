class Fisier{

private String nume,continut;
private int id,concat=0;
private static int count_id=0;
private Fisier anterior;


    public Fisier(String nume,String continut){
        this.nume=nume;
        this.continut=continut;
        count_id++;
        id=count_id;
        anterior=null;
    }
    public Fisier salveazaVersiune(){
        Fisier nou=new Fisier(nume,continut);
        nou.nume=this.nume+".bak";
        nou.anterior=this.anterior;
        this.anterior=nou;
        return nou;
    }
    public void concateneaza(Fisier fis){
        this.salveazaVersiune();
        this.continut+=fis.continut;
        concat++;
    }
    public String toString()
    {
        String s="";
        if(anterior==null)
            s=this.id+" "+this.nume+" "+this.continut;
        else
            s=s+this.id+" "+this.nume+" "+this.continut+"   <---   "+this.anterior;
        return s;

    }
    public int nrConcatenari(){
        return concat;
    }

}

class mainFisiere{

    public static void main(String[] argv){

        Fisier a=new Fisier("Tucano","cafea");
        Fisier b=new Fisier("MC","michicichi");
        Fisier c=new Fisier("Club","distractie");
        Fisier d=new Fisier("Ceva","DA");
        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(c.toString());
        b=a.salveazaVersiune();
        System.out.println(a.toString());
        c.concateneaza(d);
        c.concateneaza(a);
        //c.concateneaza(a);
        System.out.println(c.toString());
         System.out.println(c.nrConcatenari());

    }
}
