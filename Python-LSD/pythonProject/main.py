#exercitiul 3
import math
def ec_grad2(a, b, c):
    d=pow(b,2)-(4*a*c)
    if d < 0 :
            print(f"Exercitiul 3: {'Nu exista solutii'}")
    elif d==0:
            print(f"Exercitiul 3: x1=x2={-b/2*a}")
    elif d>0:
            print(f"Exercitiul 3: x1={(-b+math.sqrt(d)/2*a)};x2={(-b-math.sqrt(d)/2*a)}")
ec_grad2(3,2, -5 )

#exercitiul 4
def bisect(an):
    if an%4==0:
      if an%100==0:
        if an%400==0:
            return True
        else :
            return False
      else :
          return True
    else :
        return False
print(f"Exercitiul 4: {bisect(1000)}")

#exercitiul 5

def f(x):
    if x < -3:
        print(f"Exercitiul 5: {2*x+1}")
    elif x==0:
        print(f"Exercitiul 5:{0}")
    elif x > -3:
        print(f"Exercitiul 5:{3*pow(x,2)+6*x-5}")
f(-4)

#exercitiul 6
def interval(a,b,c):
    return (c in range(a,b)) #asa cautam un nr intr-un interval fara sa folosim condionale
print(f"Exercitiul 6: {interval(15,36,14)}")

#exercitiul 7

def sortare(a,b,c):
  maxim1=max(a,b)
  maxim2=max(a,c)
  maxim3=max(b,c)
  return (max(maxim1,maxim2,maxim3),min(maxim1,maxim2,maxim3),min(a,b,c))


print(f"Exercitiul 7: {sortare(104,106,3867)}")


#exercitiul 8

def avion(sir1,sir2):
    a=sir1[6:8]
    b=sir2[6:8]
    return int(a)-int(b)
print(f"Exercitiul 8: {avion('12:14:36','14:58:12')}")

#exercitiul 9

def cerc(raza):
    pi=3.14
    print(f"Exercitiul 9: Lungimea discului={2*pi*raza}; Aria={pi*pow(raza,2)}")
cerc(5)