class Carte{

private int nrPag=0;

    public Carte(int nr){
        nrPag=nr;
    }
    public boolean equals(Object ob){
        if(ob instanceof Carte)
            return (((Carte)ob).nrPag==nrPag);
        else
            return false;

    }
}

class mainCarte{

    public static void main(String argv[]){
        Carte c1=new Carte(180);
        Carte c2=new Carte(200);
        if(c1.equals(c2))
            System.out.println("Cele 2 carti au acelasi numar de pagini!!!");
        else
            System.out.println("Au nr diferit de pagini");

    }
}
