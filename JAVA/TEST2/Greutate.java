abstract class Greutati{
    public abstract int capacitate();
}

class Greutati_simple extends Greutati{
    private int cap;
    public Greutati_simple(int cap)
    {
        this.cap=cap;
    }
    public int capacitate(){
        return cap;
    }
}
abstract class Greutati_complex extends Greutati{//am facut o clasa in plus pentru ca la ambele capacitatea e egala cu suma capacitatilor

    protected Greutati[] v;

    public int capacitate(){
        int sum=0;
        for(int i=0;i<v.length;i++)
        {
            sum+=v[i].capacitate();
        }
        return sum;
    }
}
class Duble extends Greutati_complex{

    public Duble(Greutati g1,Greutati g2){
        v=new Greutati[2];
        v[0]=g1;
        v[1]=g2;
    }
    public void setGreutate1(Greutati g)
    {
        v[0]=g;
    }
    public void setGreutate2(Greutati g)
    {
        v[1]=g;
    }

}
class Multiple extends Greutati_complex{

    public Multiple(Greutati[] tab)
    {
        v=tab;
    }
}

class ColectieGreutati{

    private Greutati []tab;
    private int size;

    public ColectieGreutati(){
        tab=new Greutati[30];
        size=0;
    }
    public void adauga(Greutati g)
    {
        if(size<tab.length)
        {
            tab[size]=g;
            size++;
        }

    }

    public double medie(){

        int sum=0;
        for(int i=0;i<size;i++)
        {
            sum+=tab[i].capacitate();
        }
        return (double)sum/size;
    }

}

class Greutate{

    public static void main(String []argv)
    {
            Greutati g1=new Greutati_simple(20);
            Greutati g2=new Greutati_simple(30);
            Greutati g3=new Greutati_simple(35);
            Greutati g4=new Duble(g2,g3);
            Greutati[] g={new Greutati_simple(5),new Greutati_simple(10),new Greutati_simple(15),new    Greutati_simple(20)};
	Greutati g5=new Multiple(g);

	ColectieGreutati c=new ColectieGreutati();
	c.adauga(g1);
	c.adauga(g4);
	c.adauga(g5);
	System.out.println(" Medie: "+c.medie());}
    }

