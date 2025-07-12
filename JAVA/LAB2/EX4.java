class Sertar{
    private int l=0,L=0,H=0,id=0;
    private static int k=1;
    public Sertar(int lat,int Lung,int inalt){
        this.l=lat;
        this.L=Lung;
        this.H=inalt;
        id=k;
        k++;
    }
    public void tipareste(){
        System.out.println("Sertar "+id+" are"+" l="+l+" L="+L+" H="+H);
    }

}
class Birou{
    private int lat_b=0,Lung_b=0,inal_b=0;
    private Sertar s1,s2;
    public Birou(int l,int L,int h,Sertar s1,Sertar s2){
        lat_b=l;
        Lung_b=L;
        inal_b=h;
        this.s1=s1;
        this.s2=s2;
    }
     public void tiparesteBirou(){
        System.out.println("Birou"+" l="+lat_b+" L="+Lung_b+" H="+inal_b);
        s1.tipareste();
        s2.tipareste();
}
}
class EX4{

public static void main(String argv[]){

Sertar s1=new Sertar(28,50,50);
Sertar s2=new Sertar(28,50,80);
Birou b=new Birou(90,180,130,s1,s2);
b.tiparesteBirou();
}
}
