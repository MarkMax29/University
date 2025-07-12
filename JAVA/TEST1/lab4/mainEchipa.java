class Jucator{

private String nume;
private int nr_jucator;

    public Jucator(String nume,int nr_jucator){
        this.nume=nume;
        this.nr_jucator=nr_jucator;
    }
    public String returnNume(){
        return nume;
    }
    public int returnNr(){
        return nr_jucator;
    }
     @Override
        public boolean equals(Object ob)
        {
            if(ob instanceof Jucator)
            {
                Jucator jucator=(Jucator )ob;
                return nume.equals(jucator.nume) && nr_jucator==jucator.nr_jucator ;
            }
            else
                return false;
        }


}
class Echipa{

    private Jucator[] titular;
    private Jucator[] rezerva;
    private int index_titular=-1,index_rezerva=-1;
        public Echipa(Jucator[] titular,Jucator[] rezerva){
            this.titular=titular;
            this.rezerva=rezerva;
        }

        public boolean efectueazaSchimbare(Jucator un_titular,Jucator o_rezerva){

        for(int i=0;i<titular.length;i++)
        {
                if(titular[i].equals(un_titular))
                   {
                        index_titular=i;
                        break;
                    }
        }
        for(int j=0;j<rezerva.length;j++)
        {
            if(rezerva[j].equals(o_rezerva))
                {
                    index_rezerva=j;
                    break;
                }
        }
        if(index_titular!=-1 && index_rezerva!=-1)
        {
            Jucator aux=titular[index_titular];
            titular[index_titular]=rezerva[index_rezerva];
            rezerva[index_rezerva]=aux;
            return true;
        }
        return false;
    }

    public String toString(){
    String s="";
    s="Titulari: ";
        for(int i=0;i<titular.length;i++)
        {
            s=s+"(<"+titular[i].returnNume()+">, #"+titular[i].returnNr()+") ";
        }
    s=s+"\n"+"Rezerve: ";
        for(int i=0;i<rezerva.length;i++)
        {
            s=s+"(<"+rezerva[i].returnNume()+">, #"+rezerva[i].returnNr()+") ";
        }
        return s;
    }

}

class mainEchipa{

    public static void main(String[] argv){

        Jucator[] tit={new Jucator("Mark",29), new Jucator("Alex",3), new Jucator("Richard",27)};
        Jucator[] rez={new Jucator("Levi",7),new Jucator("Alex",14),new Jucator("George",36)};
        Echipa echipa=new Echipa(tit,rez);
        System.out.println(echipa);
        Jucator titu=new Jucator("Alex",3);
        Jucator reze=new Jucator("George",36);
       System.out.println(echipa.efectueazaSchimbare(titu,reze));
       System.out.println();
       System.out.println(echipa);


    }
}
