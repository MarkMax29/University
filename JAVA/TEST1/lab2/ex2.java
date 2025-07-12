/*Un sertar este caracterizat de o latime, lungime si inaltime. Un birou are doua
sertare  ̧si, evident, o latime, lungime si inaltime. Creati clasele Sertar si Birou
corespunzatoare specificatiilor de mai sus. Creati pentru fiecare clasa
constructorul potrivit astfel incat carateristicile instantelor sa fie setate la crearea acestora.
Clasa Sertar contine o metoda tipareste al carei apel va produce tiparirea pe ecran
a sertarului sub forma ”Sertar ” + l + L + H, unde l, L, H sunt valorile coresupunzatoare latimii, lungimii si inaltimii sertarului.
Clasa Birou contine o metoda ̆tipareste cu ajutorul careia se vor tipari toate componentele biroului.
Creati intr-o metoda main doua sertare, un birou si tipariti componentele biroului.
*/
class Sertar{

private int latime,Lungime,Inaltime;

    public Sertar(int l,int L,int H){
        latime=l;
        Lungime=L;
        Inaltime=H;
    }
    public void tipareste(){

        System.out.println("Sertar "+"l= "+latime+" L="+Lungime+" H="+Inaltime);
    }

}

class Birou{

private Sertar s1,s2;
private int latime,Lungime,Inaltime;

    public Birou(int l,int L,int H,Sertar s1,Sertar s2){
        latime=l;
        Lungime=L;
        Inaltime=H;
        this.s1=s1;
        this.s2=s2;
    }
    public void tiparesteBirou(){
        System.out.println("Birou are: "+"l= "+latime+" L="+Lungime+" H="+Inaltime);
        System.out.println("NR1:");s1.tipareste();
        System.out.println("NR2:");s2.tipareste();
    }

}

class ex2{

    public static void main(String argv[]){

        Sertar s1=new Sertar(20,40,30);
        Sertar s2=new Sertar(20,40,50);
        Birou b=new Birou(90,140,110,s1,s2);
        b.tiparesteBirou();
    }
}
