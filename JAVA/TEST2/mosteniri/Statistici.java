import java.util.*;

abstract class Statistica{

    protected String jurnal;
   protected Statistica()
    {
        jurnal="";
    }

    public abstract void calculeaza(ArrayList<String> secv_princ);

    public String toString()
    {
            return jurnal;
    }
}

class StatisticaNumarAparitii extends Statistica
{
    private ArrayList<String> secv_sec;

    public StatisticaNumarAparitii(ArrayList<String> secv_sec)
    {
        this.secv_sec=secv_sec;
    }

    public void calculeaza(ArrayList<String> secv_princ)
    {
        int count=0;

        for(String i:secv_princ)
        {
            for(String k:secv_sec)
            {
                if(k.equals(i))
                    {
                        count++;
                        break;
                    }
            }

        }

        jurnal+="In secventa {";
        for(String i:secv_princ)
        {
            jurnal+=i+" ";
        }
        jurnal+="} apar "+count+" siruri din secventa {";

        for(String j:secv_sec)
        {
            jurnal+=j+" ";
        }
        jurnal+="}\n";

    }

}

class StatisticaNumereNonReale extends Statistica
{
    public void calculeaza(ArrayList<String> secv_princ)
    {
        int count=0;

        for(String i:secv_princ)
        {
            try{
                Double.parseDouble(i);
            }
            catch(NumberFormatException e)
            {
                count++;
            }
        }

        jurnal+="In secventa {";

        for(String j:secv_princ)
        {
            jurnal+=j+" ";
        }
        jurnal+="} avem "+count+" siruri ce nu sunt numere reale\n";
    }
}

class Executor{
    private ArrayList<Statistica> lista;

    public Executor(ArrayList<Statistica> lista)
    {
        this.lista=lista;
    }

    public void executa(ArrayList<String> secv)
    {
        for(Statistica i:lista)
        {
            i.calculeaza(secv);
        }
    }

    public String toString()
    {
        String s="";
        for(Statistica i:lista)
        {
            s+=i.toString();
        }
        return s;
    }
}

class Statistici{
    public static void main(String[] argv)
    {
        ArrayList<String> sir1=new ArrayList<String>();
        sir1.add("mere");
        sir1.add("pere");
        sir1.add("banane");
        StatisticaNumarAparitii sta1=new StatisticaNumarAparitii(sir1);
        StatisticaNumereNonReale sta2=new StatisticaNumereNonReale();

	ArrayList<Statistica> l2=new ArrayList<Statistica>();
	l2.add(sta1);
	l2.add(sta2);

	Executor e=new Executor(l2);

	ArrayList<String> sec1=new ArrayList<String>();
	sec1.add("Ana");
	sec1.add("are");
	sec1.add("mere");
	ArrayList<String> sec2=new ArrayList<String>();
	sec2.add("Maria");
	sec2.add("are");
	sec2.add("2.124");

	e.executa(sec1);
	System.out.println(e);

	e.executa(sec2);
	System.out.println(e);
    }
}


