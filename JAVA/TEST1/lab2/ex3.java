class Complex{

private double re,im;
private static int count=0;
    public Complex(double re,double im){
        this.re=re;
        this.im=im;
    }

    public double calculModul(){
        return Math.sqrt(re*re+im*im);
    }
    public void tiparire(){
        System.out.println(re+"+"+"i*"+im);
        count++;
    }
    public Complex suma(Complex ob){
        this.re+=ob.re;
        this.im+=ob.im;
        return this;
    }
    public int nrTipariri(){
        return count;
    }

}
class ex3{
    public static void main(String argv[]){
        Complex c1=new Complex(5,6);
        Complex c2=new Complex(7,8);
        System.out.println("Modulul= "+c1.calculModul());
        c1.tiparire();
        System.out.println("Modulul= "+c2.calculModul());
        c2.tiparire();
        c1.suma(c2);
        c1.tiparire();
        System.out.println("Nr de afisari pe ecran= "+c2.nrTipariri());


    }
}
