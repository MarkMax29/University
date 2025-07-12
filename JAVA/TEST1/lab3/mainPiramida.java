class Piramida{

private int n;

    public Piramida(int n)
    {
        this.n=n;
    }
    public void tiparirePiramida()
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=n-i+1;j>=1;j--)
            {
                if(i==n)
                    System.out.print(i+" --> n");
                else
                    System.out.print(i+" ");
            }
            System.out.println();
        }
    }
}

class mainPiramida{

    public static void main(String argv[]){

        Piramida p=new Piramida(4);
        p.tiparirePiramida();
    }
}
