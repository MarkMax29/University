class Patrat{

private int l=0;

    public Patrat(){
        l=10;
    }
    public Patrat(int l){
        this.l=l;
    }
    public void tiparire(){
        System.out.println("Patrat "+l+" Aria "+l*l);
    }

}
class mainPatrat{

    public static void main(String argv[]){
        Patrat p1=new Patrat();
        Patrat p2=new Patrat(20);
        p1.tiparire();
        p2.tiparire();
        p2=p1;
        p2.tiparire();
    }
}
