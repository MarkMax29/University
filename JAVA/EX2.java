class Foo{
    public int a=0;

    public void setA(int a){
        this.a=a;
    }
    public void copy(Foo other){
        this.a=other.a;
    }
    void resetA(){
    a=0;
    }
}

public class EX2{
    public static void main(String[] args){
    Foo foo=new Foo();
    foo.setA(2);
    System.out.println(foo.a);

    Foo foo2=new Foo();
    foo2.setA(10);
    foo.copy(foo2);
    System.out.println(foo.a+" "+foo2.a);

    }
}
