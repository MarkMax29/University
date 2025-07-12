class Figura{
private float arie;

    public Figura(float arie){
        this.arie=arie;
    }
    public float returnArie(){
        return arie;
    }
}

class Desen{

private String titlu;
Figura[] v=new Figura[1024];
private int index=0;
private float medie=0;

   public Desen(String titlu)
    {
        this.titlu=titlu;
    }

   public boolean adaugaFigura(Figura f){
        if(v.length>index)
        {
            for(int i=0;i<index;i++)
            {
                if(v[i].equals(f))
                    return false;
            }
            v[index]=f;
            index++;
            return true;
        }
        return false;

    }
    public String toString(){
        String s="Titlu desen <"+titlu+">: ";
        for(int i=0;i<index;i++)
        {
            s=s+"Figura"+(i+1)+"(ARIA="+v[i].returnArie()+");   ";
        }
        return s;


    }

    public float medieArie(){
        if(v==null)
            return 0;
        for(int i=0;i<index;i++)
        {
         medie=medie+v[i].returnArie();
        }
        return medie/index;
    }
}
class mainFiguri{

    public static void main(String[] argv){

        Desen des=new Desen("Abstract");
        Figura fig1=new Figura(16);
        Figura fig2=new Figura(25);
        Figura fig3=new Figura(32);
       System.out.println(des.adaugaFigura(fig1));
        System.out.println(des.adaugaFigura(fig2));
         System.out.println(des.adaugaFigura(fig3));
          System.out.println(des.adaugaFigura(fig2));
           System.out.println(des+"\n");
            System.out.println(des.medieArie());
    }
}
