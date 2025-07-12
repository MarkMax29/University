class Sume{

    public static int suma(int a,int b){
        return a+b;
    }
    public static int suma(int a,int b,int c){
        return suma(a,b)+c;
    }
    public static int suma(int a,int b,int c,int d){
        return suma(a,b,c)+d;
    }

}

class mainSume{

    public static void main(String argv[]){
        System.out.println("Suma de 2: "+Sume.suma(1,2)+" Suma de 3: "+Sume.suma(1,2,3)+" Suma de 4: "+Sume.suma(1,2,3,4));
    }
}
