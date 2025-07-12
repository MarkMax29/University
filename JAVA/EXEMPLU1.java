class Punct{
         static int x=0;
          int y=0;

        public Punct(int x,int y){
            this.x=x;
            this.y=y;
        }
        public Punct(int a){
            x=a;
        }
        public void printX(){
            System.out.println("VALOARE x="+x);
        }
        public int getY(){
            return y;
        }
}
class EXEMPLU1{

public static void main(String argv[]){
    Punct p=new Punct(3);
   // p.Punct(3,4);
    System.out.println("x="+p.x+" "+"y="+p.y);
    System.out.println();
    Punct p1=new Punct(4,5);
    System.out.println("x="+p.x+" "+"y="+p1.y);

}

}
