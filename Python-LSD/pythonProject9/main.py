import functools
import sys

#ex 1 multimi
"""1. Scrieți o funcție care ia ca parametru o mulțime și o tipărește pe o linie, între acolade { } și cu virgulă între elemente. 
Input: {1,2,3}; Output: {1,2,3}"""

def afis(mult):
    print("{",end="")
    functools.reduce(lambda acc,el: print(el,end=","),mult,None)
    sys.stdout.write('\b') #va muta cursorul de imprimare cu o pozitie inapoi adica daca afiseaza virgula dp 3 va disparea """
    print("}")
afis({1,2,3})


#ex2 multimi

"""2. Scrieți o funcție care ia o listă de perechi (de tip precizat) și returnează mulțimea elementelor de pe prima poziție din fiecare pereche (variante: a doua poziție; ambele poziții, dacă sunt de același tip).

Input: [(1,2), (3,4)]; Output: {1,3}"""
def ex2(lista):
    return functools.reduce(lambda multime, pereche: multime| {pereche[0],pereche[1]},lista,set())
print(ex2([(1,2),(3,4)]))

#ex3 multimi
"""3. Implementați funcția standard filter care ia ca parametri o funcție booleană f și o mulțime s și returnează mulțimea elementelor din s care satisfac funcția f.

Input: lambda x: x % 2 == 0, {1, 2, 3, 4}; Output: {2, 4}"""
def f(x):
    if x%2==0:
        return True
    else:
        return False
def filter(f,s):
    return functools.reduce(lambda acc,el: acc|{el} if f(el) else acc,s,set())
print(filter(f,{1,2,3,4}))
#ex4-multimi
"""4. Implementați funcția standard partition care ia ca parametri o funcție booleană f și o mulțime s și returnează o pereche de mulțimi, cu elementele din s care satisfac, respectiv nu satisfac funcția f.

Input: lambda x: x % 2 == 0, {1, 2, 3, 4}; Output: ({2, 4}, {1, 3})"""
def partition(f,s):
    return (filter(f,s),s-filter(f,s))
print(partition(f,{1,2,3,4,5}))

#ex5-multimi

"""5. Scrieți o funcție care ia o lista de mulțimi (de exemplu, de șiruri), și returnează reuniunea (variantă: intersectia) mulțimilor."""
def ex5(lista):
    return functools.reduce(lambda acc,el_mul: acc|el_mul,lista,set())
print(ex5([{'a'},{'b'},{'c'}]))
#ex6-multimi
"""6. Scrieți o funcție care returnează mulțimea cifrelor unui număr. Scrieți apoi altă funcție care ia o mulțime de numere și returnează reuniunea/intersecția dintre mulțimile cifrelor lor.

Input: {1234, 123, 127}; Output: reuniune: {1, 2, 3, 4, 7}; intersectie: {1, 2}"""


#ex1 -dictionare
def adauga_pereche_in_dictionar(dictionar, pereche):
    cheie, valoare = pereche
    if cheie in dictionar.keys():
        dictionar[cheie] = dictionar[cheie] + valoare
    else:
        dictionar[cheie] = valoare

    return dictionar

def convert_pair(lista_perechi):
    return functools.reduce(lambda dictionar, pereche: adauga_pereche_in_dictionar(dictionar, pereche) , lista_perechi, {} )

print(convert_pair( [('a', 7), ('b', 5), ('c', 2), ('a', 3), ('b', 3)]))


#ex2-dictionar
""" 2. Scrieți o funcție care ia o listă de șiruri de caractere și creează un dicționar în care fiecare șir e asociat cu numărul aparițiilor din listă.

Input: ["aaa", "bbb", "aabbb"]; Output: {'a': 5, 'b': 6}"""

cheie = "cheie"
stanga = "stanga"
dreapta = "dreapta"


nod1 = {cheie: 1, stanga: None, dreapta: None}  # frunza
nod7 = {cheie: 7, stanga: None, dreapta: None}  # frunza
nod4 = {cheie: 4, stanga: None, dreapta: None}  # frunza
nod5 = {cheie: 5, stanga: nod4, dreapta: nod7}
radacina = {cheie: 2, stanga: nod1, dreapta: nod5}

def afisare_nivel(arbore, nivel, nivel_curent=1):
    if arbore is not None:
        if nivel == nivel_curent:
            print(arbore[cheie], end= ", ")
        else:
            afisare_nivel(arbore[stanga], nivel, nivel_curent+1)
            afisare_nivel(arbore[dreapta], nivel, nivel_curent+1)
    else:
        print("", end="")

print("\nafisare nivel 2: ")
afisare_nivel(radacina, 1)


def list_ar(arbore):
    if arbore is not None:
        if (arbore[stanga] is None and arbore[dreapta] is not None)or(arbore[stanga] is not None and arbore[dreapta] is None):
            return [arbore[cheie]]+list_ar(arbore[stanga])+list_ar(arbore[dreapta])
        else:
            return list_ar(arbore[stanga])+list_ar(arbore[dreapta])
    else:
     return []
print(list_ar(radacina))