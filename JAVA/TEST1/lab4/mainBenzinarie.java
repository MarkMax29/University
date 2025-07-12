class Masina{

private String nr_inmat;
private int benzina;

    public Masina(String nr_inmat,int benzina){
        this.nr_inmat=nr_inmat;
        this.benzina=benzina;
    }
    public String returnNR_INMAT(){
        return nr_inmat;
    }
    public int returnBenzina(){
        return benzina;
    }

}
class Benzinarie{

    private int cant_benzina;
    Masina[] v=new Masina[10];//vectorul de asteptari
    private int index=0;
    public Benzinarie(int cant_benzina)
    {
        this.cant_benzina=cant_benzina;
    }

    public boolean alimenteazaMasina(Masina m){

        if(cant_benzina>=m.returnBenzina())
            {
                cant_benzina=cant_benzina-m.returnBenzina();
                return true;
            }
        else if(index<v.length)
           {
                v[index]=m;
                index++;
                return true;

            }
            return false;
        }


    public String toString(){
        String s="";
        s="Coada benzinarie: ";
        for(int i=0;i<index;i++)
        {
            s=s+"Masina"+(i+1)+" :("+v[i].returnNR_INMAT()+", "+v[i].returnBenzina()+"); ";
        }
    return s;
    }

    public void alimenteazaBenzinarie(int benzinaDeadaugat)
    {
        cant_benzina+=benzinaDeadaugat;
        for(int i=0;i<index;i++)
        {
            if(cant_benzina>=v[i].returnBenzina())
                {
                cant_benzina=cant_benzina-v[i].returnBenzina();
                for(int j=i;j<index-1;j++)
                    v[j]=v[j+1];
                index--;
                }
        }


    }

}
class mainBenzinarie{

    public static void main(String[] argv){

        Benzinarie benz=new Benzinarie(10);
        Masina m1=new Masina("SM MRK04",5);
        Masina m2=new Masina("TM MAX29",10);
        Masina m3=new Masina("B HRV05",15);
        System.out.println(benz);
        System.out.println(benz.alimenteazaMasina(m1));
        System.out.println(benz.alimenteazaMasina(m2));
        System.out.println(benz.alimenteazaMasina(m3));
        System.out.println(benz);
        benz.alimenteazaBenzinarie(15);
        System.out.println(benz);
    }
}
