class Remorca{

private int cant_cutii;
private String nr_inmat;
private static Remorca anterior=null;
    public Remorca(int cant_cutii,String nr_inmat)
    {
        this.cant_cutii=cant_cutii;
        this.nr_inmat=nr_inmat;
    }
    public Remorca(String nr_inmat)
    {
        if(anterior==null)
        {
            this.cant_cutii=10;
            anterior=this;
        }
        else
        {
            this.cant_cutii+=1+anterior.cant_cutii;
            anterior=this;
        }

    }
    public String retNrinmat()
    {
        return nr_inmat;
    }
    public int retNrcutii()
    {
        return cant_cutii;
    }

}

class Tir{

    Remorca[] v=new Remorca[5];
    private int index=0;
    private int sum1=0,sum2=0;
    private static int count_tir=1;

    public boolean adaugaRemorca(int nr_cutii,String inmatr)
    {
        if(index>=5)
            return false;
        v[index]=new Remorca(nr_cutii,inmatr);
        index++;
        return true;

    }
    public Remorca stergereRemorca(String nr_inmatriculare)
    {
        for(int i=0;i<index;i++)
        {
            if(v[i].retNrinmat().equals(nr_inmatriculare))
            {
                Remorca ref=v[i];
                for(int j=i;j<index-1;j++)
                {
                    v[j]=v[j+1];
                }
                index--;
                return ref;
            }
        }
        return null;
    }

    public boolean equals(Object ob)
    {
        if(ob==null)
            return false;
        if(ob instanceof Tir)
        {
            Tir t1=(Tir) ob;
            for(int i=0;i<index;i++)
            {
                sum1+=v[i].retNrcutii();
                sum2+=t1.v[i].retNrcutii();
            }
            if(sum1==sum2)
                return true;
        }

         return false;

    }
    public String toString()
    {
        String s="";
        s="TIR "+count_tir+" ->";
        count_tir++;
       for(int i=0;i<index;i++)
        {
            if(i!=index-1)
                s=s+"R"+(i+1)+"("+v[i].retNrinmat()+", "+v[i].retNrcutii()+") ->";
            else
                s=s+"R"+(i+1)+"("+v[i].retNrinmat()+", "+v[i].retNrcutii()+")";

        }
        return s;

    }

}

class mainTiruri{

public static void main(String[] argv){

    Tir t1=new Tir();
        t1.adaugaRemorca(10,"ABC");
        t1.adaugaRemorca(15,"DEF");
        t1.adaugaRemorca(25,"GHI");
    Tir t2=new Tir();
        t2.adaugaRemorca(13,"ESTE");
        t2.adaugaRemorca(17,"TIMIS");
        t2.adaugaRemorca(5,"SM");
    Remorca sters;
    System.out.println(t1.toString()+"\n");
    System.out.println(t2.toString()+"\n");

    if(t1.equals(t2))
        System.out.println("\nSunte egale");
    else
        System.out.println("\nNu sunt egale");

    sters=t1.stergereRemorca("DEF");
    System.out.println("\nRemorca stearesa este: R("+sters.retNrinmat()+", "+sters.retNrcutii()+")");
    System.out.println(t1.toString());


}
}
