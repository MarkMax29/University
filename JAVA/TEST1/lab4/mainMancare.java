class FelDeMancare{

private String nume_fel_mancare;
private int calorii;

    public FelDeMancare(String nume_fel_mancare,int calorii){
        this.nume_fel_mancare=nume_fel_mancare;
        this.calorii=calorii;
    }
    public int getCalorii(){
        return calorii;
    }
    public String getNume(){
        return nume_fel_mancare;
    }

    public boolean equals(Object obj){

        if(obj instanceof FelDeMancare)
        {
            if(calorii==(((FelDeMancare)obj)).calorii)
                return true;
        }
        return false;
    }
    public String toStringMancare(int i){
        String s="";
        s="Mancare"+(i)+"("+nume_fel_mancare+", "+calorii+"); ";
        return s;
    }
}
class Meniu{

private int maxim_calorii,index=0;
private FelDeMancare[] v=new FelDeMancare[10];

    public Meniu(int maxim_calorii)
    {
        this.maxim_calorii=maxim_calorii;
    }

    public boolean adaugaFelDeMancare(FelDeMancare fel){
        int nr_calorii_actual=0;
        if(index<v.length)
        {
            for(int i=0;i<index;i++)
            {
                nr_calorii_actual+=v[i].getCalorii();
            }
            if(nr_calorii_actual<maxim_calorii)
                {
                    v[index]=fel;
                    index++;
                    return true;
                }

        }
        return false;

    }

    public String toString(){
        String s="Meniu:\n";
        for(int i=0;i<index;i++)
        {
            s=s+v[i].toStringMancare(i+1);
        }
        return s;

    }

    public boolean schimbaFelDeMancare(FelDeMancare fel_nou){
        int contor=-1;
        for(int i=0;i<index;i++)
        {
            if(v[i].equals(fel_nou))
            {
                contor=i;
                break;
            }
        }

        if(contor!=-1)
        {
            FelDeMancare aux=v[contor];
            v[contor]=fel_nou;
            fel_nou=aux;
            return true;
        }
        return false;

    }

}

class mainMancare{

    public static void main(String[] argv){

        Meniu m=new Meniu(150);
        FelDeMancare fel1=new FelDeMancare("Pizza",50);
        FelDeMancare fel2=new FelDeMancare("Paste",80);
        FelDeMancare fel3=new FelDeMancare("Mcchicken",20);
        FelDeMancare fel4=new FelDeMancare("Mamaliga",10);

        System.out.println(m.adaugaFelDeMancare(fel1));
        System.out.println(m.adaugaFelDeMancare(fel2));
        System.out.println(m.adaugaFelDeMancare(fel3));
        System.out.println(m.adaugaFelDeMancare(fel4));
        System.out.println();
        System.out.println(m);
        FelDeMancare nou=new FelDeMancare("Sarmale",80);
        System.out.println(m.schimbaFelDeMancare(nou));
        System.out.println();
        System.out.println(m);
    }
}
