import java.util.*;

class WrongQualityIndicatorException extends RuntimeException
{
    public WrongQualityIndicatorException(){
        super("WrongQualityIndicatorException!\n");
    }
}
class WrongComponentComplexityIndicatorException extends RuntimeException
{
    public WrongComponentComplexityIndicatorException(){
        super("WrongComponentComplexityIndicatorException!\n");
    }
}


abstract class Test{
     public abstract int getNumarTeste();
}
abstract class TesteBaza extends Test{
    protected String nume;
    protected int indicator_calitate;
    public TesteBaza(String nume,int indicator_calitate) throws WrongQualityIndicatorException
    {
        if(indicator_calitate>=1 && indicator_calitate<=10)
             this.indicator_calitate=indicator_calitate;
        else throw new WrongQualityIndicatorException();
        this.nume=nume;

    }

    public int getNumarTeste()
    {
        return 1;
    }

    public abstract String toString();

}

class IntegrationTest extends TesteBaza{

    public IntegrationTest(String nume,int indicator_calitate) throws WrongQualityIndicatorException
    {
        super(nume,indicator_calitate);
    }

    public String toString(){

        return "IntegrationTest (name= "+nume+", quality indicator= "+indicator_calitate+"); ";
    }

}

class ComponentTest extends TesteBaza{
    protected int complex_component;

    public ComponentTest(String nume,int indicator_calitate,int complex_component) throws WrongQualityIndicatorException,WrongComponentComplexityIndicatorException
    {
        super(nume,indicator_calitate);
        if(complex_component>0)
            this.complex_component=complex_component;
        else throw new WrongComponentComplexityIndicatorException();


    }
    public String toString()
    {
        return "ComponentTest (nume= "+nume+", qulity indicator= "+indicator_calitate+", complexity component= "+complex_component+"); ";
    }
}

class TestSuite extends Test{

    private ArrayList<Test> lista;

    public TestSuite()
    {
        lista=new ArrayList<Test>();
    }
    public int getNumarTeste()
    {
        int sum=0;
        for(Test i:lista)
        {
            sum+=i.getNumarTeste();
        }
        return sum;
    }

    public boolean addNewIntegrationTest(String nume,int indicator_calitate)
    {
        try{
            IntegrationTest x=new IntegrationTest(nume,indicator_calitate);
            lista.add(x);
            return true;
        }catch(WrongQualityIndicatorException e)
            {
                return false;
            }

    }
    public boolean addNewComponentTest(String name,int indicator_calitate,int complex_component) throws WrongComponentComplexityIndicatorException //cand zice ca propaga
    {
        try{
            ComponentTest y=new ComponentTest(name,indicator_calitate,complex_component);
            lista.add(y);
            return true;
        }
        catch(WrongQualityIndicatorException e)
        {
            return false;
        }
    }

    public String toString()
    {
        String s="TestSuite(";
        for(Test i:lista)
        {
            s+=i.toString();
        }
        s=s+")";
        return s;
    }
}

class Soft{

    public static void main(String []argv)
    {
        TestSuite t=new TestSuite();
        try{
            t.addNewIntegrationTest("Ion",7);
            t.addNewIntegrationTest("Alex",11);//o sa dea exception false
            t.addNewComponentTest("Kevin",4,3);
            t.addNewComponentTest("Mark",8,-2);//da exception si da mesaj
        }
        catch(WrongComponentComplexityIndicatorException e)
        {
            System.out.println(e.getMessage());
        }
        System.out.println(t+"\n"+t.getNumarTeste());

    }
}
