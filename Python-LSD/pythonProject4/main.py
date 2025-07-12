#exercitiul 1b >>>altfel nu stiu cum sa fac
import functools
def cond(x):
    if(x%10%2==0):
        return True
    else:
        return False
def cifre(n):
    if n!=0:
        if(cond(n)):
             return cifre(n//10) + [n%10]
        else:
             return cifre(n//10)
    else:
        return []

print(cifre(1284635))


#exercitiul 1c
def afis(lista):
 lista2=list(filter(lambda x: x%2==0,lista))
 return functools.reduce(lambda x,y:10*x+y,lista2,0)
print(afis([1,2,3,4,5,6,8]))

"""ex 2/"""
def creare_lista(a,b,d):
    if a<b:
        if a%d==0:
            return [a]+creare_lista(a+1,b,d)
        else:
            return creare_lista(a+1,b,d)
    else:
        return[]
def fromto(a,b,d):
    lista3= creare_lista(a,b,d)
    return functools.reduce(lambda a,b:a if a>b else b,lista3)
print(fromto(2,36,5))

"""ex6/a"""
def f(x):
    if x>4:
        return True
    else:
        return False
def countif(lista_nou):
    return functools.reduce(lambda a,b: a+1 if f(b) else a,lista_nou,0)
print(countif([4,3,16,78,5,2,1]))

"""ex6/b"""
def sumif(lista_nou):
    return functools.reduce(lambda a,b: a+b if f(b) else a,lista_nou,0)
print(sumif([4,3,16,78,5,2,1]))

"""ex5/a"""
lista_nou=[4,3,16,78,5,2,1]
def filter(lista_nou):
    return functools.reduce(lambda a,b: a+[b] if f(b) else a,lista_nou,[])
print(filter(lista_nou))

"""ex5/b"""
def exists(x,lista_nou):
    if(lista_nou==[]):
        return False
    return x==lista_nou[0] or exists(x,lista_nou[1:])
print(exists(78,lista_nou))