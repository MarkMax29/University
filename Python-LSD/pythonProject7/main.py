#exercitiul 4
import functools
def f(x):
    if(x in "aeiou"):
        return True
    else:
        return False

def exists(func,dictionar):
    contor=functools.reduce(lambda acc,pereche:acc+1 if(func(pereche[0])) else acc,list (dictionar.items()),0)
    if(contor!=0):
        return True
    else:
        return False
print(f"Raspuns ex 4 a: {exists(f,{'a': 5, 'e': 7, 'i': 1})}")

def for_all(func,dictionar):
    contor=functools.reduce(lambda acc,pereche:acc+1 if(func(pereche[0])) else acc,list (dictionar.items()),0)
    if(contor==len(dictionar.items())):
        return True
    else:
        return False
print(f"Raspuns exercitiul 4 b: {for_all(f,{'a': 5, 'e': 7, 'i': 1})}")

#exercitiul 5

def create_dict(pereche,dict,f):
    cheie,valoare=pereche
    dict[cheie]=f(valoare)
    return dict
def map_fct(f,dictionar):
    return functools.reduce(lambda dict_nou,pereche:create_dict(pereche,dict_nou,f),list(dictionar.items()),dict())
print(f"Exercitiul 5: {map_fct(lambda x:x+1,{'a': 5, 'b': 7, 'c': 6})}")

#exercitiul 6
def la_fel(dict,lista):
    return functools.reduce(lambda mul,val:mul|{val[1]} if(val[0]==lista[len(mul)])else mul,list(dict.items()),set())

print(f"Exercitiul 6: {la_fel({'aa': 5, 'bb': 7, 'ca': 6}, ['aa', 'bb', 'c'])}")