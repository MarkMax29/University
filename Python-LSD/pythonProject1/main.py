#exercitiul 1
def arg(a,b,c):
    if a!=b!=c :
        print(f"arg dif={3} toate argumentele sunt distincte")
    if(a==b and a==c):
        print(f"arg dif={0} toate argumentele sunt egale")
    else:
        if(a==b and a!=c):
            print(f"arg dif={1} argumentele 1 si 2 sunt egale")
        elif(a==c and b!=c):
            print(f"arg dif={1} argumentele 1 si 3 sunt egale")
        else:
            print(f"arg dif={1} argumentele 2 si 3 sunt egale")

arg(1,2,2)

import operator
import math

#exercitiul 3 a)
def fct(f,g):
    return lambda x: f(x)+g(x)
def a(x):
    return x*5
def b(x):
    return x/2

suma=fct(a,b)
print(suma(10))

#exercitiul 3 b)--- nu inteleg cum se face

def fct2(ope,f,g):
    return ope(f,g)


#exercitiul 4

def anonim(x):
    return (lambda x: x+15)(x)
print(anonim(5))