class Card{

private String numar_card;
private float sold;

    public Card(String numar_card,float sold){
        this.numar_card=numar_card;
        this.sold=sold;
    }
    public String returnNumar(){
        return numar_card;
    }
    public float returnSold(){
        return sold;
    }


}
class Portofel{
private String nume_proprietar;
Card[] v=new Card[6];
private int index=0;

    public Portofel(String nume_proprietar)
    {
            this.nume_proprietar=nume_proprietar;
    }

    public boolean adaugaCard(String nr_card,float soldul){
        if(index<v.length)
        {
            Card c=new Card(nr_card,soldul);

            for(int i=0;i<index;i++)
            {
                if(v[i].returnNumar().equals(nr_card))
                 return false;
            }
          v[index]=c;
          index++;
          return true;
        }
        return false;
    }

    public String toString(){
        String s="";
        s="Portofelul lui "+nume_proprietar+": ";
        for(int i=0;i<index;i++)
        {
            s=s+"Card"+(i+1)+":("+v[i].returnNumar()+", "+v[i].returnSold()+")  ";
        }
        return s;
    }
    public float calculeazaSold(){

    float sum=0;
        for(int i=0;i<index;i++)
        {
            sum=sum+v[i].returnSold();
        }
    return sum;
    }
}
class mainPortofel{

    public static void main(String[] argv){

    Portofel p=new Portofel("Mark");
   /* Card c1=new Card("231564",1200);
    Card c2=new Card("654798",500);
    Card c3=new Card("548654",3000);
    Card c4=new Card("231564",4500);
*/
    System.out.println(p.adaugaCard("231564",1200));
    System.out.println(p.adaugaCard("654798",500));
    System.out.println(p.adaugaCard("548654",3000));
    System.out.println(p.adaugaCard("231564",4500));
    System.out.println();
    System.out.println(p);
    System.out.println("Soldul tuturor cardurilor: "+p.calculeazaSold());

    }
}
