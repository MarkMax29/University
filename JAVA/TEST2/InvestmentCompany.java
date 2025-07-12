interface Risky{
    public double getRisky();
}

class Membru{
    private int varsta;
    private String nume;

    public Membru(int varsta,String nume){
        this.nume=nume;
        this.varsta=varsta;
    }

    public String getNume(){
        return nume;
    }
    public int getVarsta(){
        return varsta;
    }


}

abstract class Project implements Risky{

    private String titlu,obiectiv;
    protected long[] fonduri=new long[5];
    private Membru manager;
    protected Membru[] membrii;
    protected int size,size_fond;

    public Project(String titlu,String obiectiv,long[] fonduri,Membru manager)
    {
        this.titlu=titlu;
        this.obiectiv=obiectiv;
        this.fonduri=fonduri;
        this.manager=manager;
        membrii=new Membru[15];
        size=0;
        size_fond=fonduri.length;

    }

    public abstract void addMember(Membru m);
    public long getFonduri(){

        long sum=0;
        for(int i=0;i<size_fond;i++)
        {
            sum=sum+fonduri[i];
        }
        return sum;
    }

     public String toString()
    {
        return titlu;
    }

}

abstract class ComMili extends Project{

    private String deadline;

    public ComMili(String titlu,String obiectiv,long[] fonduri,Membru manager,String deadline)
    {
        super(titlu,obiectiv,fonduri,manager);
        this.deadline=deadline;
    }

    public void addMember(Membru m)
    {
        if(size<membrii.length)
        {
            membrii[size]=m;
            size++;
        }
    }
}
class Comercial extends ComMili{

    private long fond_marketing=getFonduri()/2;
    private int echipe=4;
    public Comercial(String titlu,String obiectiv,long[] fonduri,Membru manager,String deadline)
    {
        super(titlu,obiectiv,fonduri,manager,deadline);
    }
    public long getFondMarketing(){
        return fond_marketing;
    }
    public int getEchipe()
    {
        return echipe;
    }
    public double getRisky(){
    if(size==0 || this.getFonduri()==0)
	    return 0;

        return echipe*3/size/this.getFonduri()-this.getFondMarketing();
    }

}

class Militar extends ComMili {

    private String parola;

    public Militar(String titlu,String obiectiv,long[] fonduri,Membru manager,String deadline,String parola)
    {
        super(titlu,obiectiv,fonduri,manager,deadline);
        this.parola=parola;
    }
    public double getRisky(){
        return size/parola.length()/this.getFonduri();
    }

}

class OpenSource extends Project{

    private String maillinlist;

    public OpenSource(String titlu,String obiectiv,long[] fonduri,Membru manager,String maillinlist)
    {
        super(titlu,obiectiv,fonduri,manager);
        this.maillinlist=maillinlist;
    }

    public void addMember(Membru m)
    {
        if(size==membrii.length)
        {
            Membru[] aux=new Membru[2*membrii.length];
            for(int i=0;i<size;i++)
            {
                aux[i]=membrii[i];
            }
            membrii=aux;
        }
        membrii[size]=m;
        size++;
    }

    public double getRisky(){
        return size/this.getFonduri();
    }

}

class InvestmentCompany{

    private Project []v=new Project[10];
    private int nr_proi;

    public InvestmentCompany()
    {
        nr_proi=0;

    }
    public void addProject(Project p)
    {
        if(nr_proi<v.length)
        {
            v[nr_proi]=p;
            nr_proi++;
        }
    }

    public Project getBestInvestment(){

        if(nr_proi==0)
            return null;
        Project aux=v[0];
        double mini=v[0].getRisky();
        for(int i=1;i<nr_proi;i++)
        {
            if(v[i].getRisky()<mini)
            {
                mini=v[i].getRisky();
                aux=v[i];
            }
        }
        return aux;
    }

    public static void main(String[] argv)
    {
        long[] l1={1000,2000};
        Project p1=new Militar("Proiect1","Clonare",l1,new Membru(25,"Mark"),"24.12.2024","100100");

    p1.addMember(new Membru(54,"Alex"));
    p1.addMember(new Membru(19,"Maria"));
    p1.addMember(new Membru(24,"Ana"));
    p1.addMember(new Membru(40,"Marcel"));
    p1.addMember(new Membru(53,"Hilda"));
    p1.addMember(new Membru(34,"Linda"));

      long[] l2={2000};
        Project p2=new Comercial("Proiect2","AI",l2,new Membru(28,"Levi"),"15.04.2024");

    p2.addMember(new Membru(14,"Alexia"));
    p2.addMember(new Membru(16,"Mara"));
    p2.addMember(new Membru(23,"Angel"));
    p2.addMember(new Membru(20,"Maricica"));

System.out.println(p1);
System.out.println(p2);
InvestmentCompany y=new InvestmentCompany();
	y.addProject(p1);
	y.addProject(p2);
	Project p_final=y.getBestInvestment();
	System.out.println(p_final);
    }

}


