class Person{
    private String name;

    public Person(String name){
        this.name=name;
    }
    public String getName(){return name;}
}
class Employee extends Person{

    private int salary;
    public Employee(){
        this("name",10);
    }

    public Employee(String name,int salary){
        super(name);
        this.salary=salary;
    }

    public int getSalary(){
        return salary;
    }
}
class Janitor extends Employee{}
class Programmer extends Employee{}
class Manager extends Employee{
    public void startMeeting(){
        System.out.println("Meeting started");
    }
}
class EX{
public static void main(String[] args){
    Person p=new Programmer();
    /*System.out.println(p.getName());
  //  System.out.println(p.getSalary());//eroare
    Person[] person={
        new Janitor(),
        new Employee("a",2),
        new Programmer(),
        new Employee("b",5)
    };
    for(int i=0;i<person.length;i++)
        {
            System.out.println(person[i].getName());
        }
}
*/
System.out.println(p instanceof Employee);
System.out.println(p instanceof Person);
System.out.println(p instanceof Programmer);
System.out.println(p instanceof Janitor);//de ce ????
Employee e=new Employee();
System.out.println(e instanceof Person);
System.out.println(e instanceof Programmer);
}
}

class Baz{
protected int foo=5;
}

class Foo extends Baz{
    protected int foo=2;
}
class Bar extends Foo{
private int foo=3;

void foo(){
    System.out.println(foo);//3
    System.out.println(super.foo);//2
    System.out.println(((Baz)this).foo);//5
}}
