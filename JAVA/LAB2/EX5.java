class Complex{
private double re=0,im=0;
private static int nrc=0;
    public Complex(double real,double imag)
    {
        this.re=real;
        this.im=imag;
    }
    public double calculModul()
    {
       return Math.sqrt(re*re+im*im);
    }

    public Complex suma(Complex ob)
    {
        double sumReal=ob.re+this.re;
        double sumIm=ob.im+this.im;
        return new Complex(sumReal,sumIm);
    }
    public void tipareste()
    {
    System.out.println(re+"+"+"i*"+im);
    nrc++;
    }
    public static int numara()
    {
    return nrc;
    }
}

class EX5{

public static void main(String argv[])
{
Complex c1=new Complex(5,6);
c1.tipareste();
System.out.println();
System.out.println("Modulu="+c1.calculModul());
Complex c2=new Complex(6,7);
Complex suma=c1.suma(c2);
suma.tipareste();
System.out.println("Nr de afisari de nr complexe= "+c1.numara());
}
}
