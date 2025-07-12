class Masina{
    int km=0;
    private Masina(int c){///imi vaa da eroare pentru ca constructorul Masina este privat si n-are acces la alta clasa
    km=c;
    }
}

class EX1{

    public static void main(String argv[])
    {
        Masina m=new Masina(455);
        System.out.println(m.km);
    }
}
