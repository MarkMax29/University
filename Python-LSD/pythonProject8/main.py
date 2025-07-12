"""
1. Scrieți o funcție care ia un arbore binar și returnează lista nodurilor
 care au un singur fiu. Ordinea nodurilor în listă va fi cea din traversarea
 în inordine.

2. Scrieți o funcție care ia un arbore binar și returnează numărul total de noduri
 din arbore.

"""

cheie = "cheie"
stanga = "stanga"
dreapta = "dreapta"

nod5 = {cheie: 5, stanga: None, dreapta: None}
nod4 = {cheie: 4, stanga: None, dreapta: None}
nod3 = {cheie: 3, stanga: None, dreapta: nod5}
nod2 = {cheie: 2, stanga: nod4, dreapta: nod3}
radacina = {cheie: 1, stanga: nod2, dreapta: None}


# ex1
def copil(arbore):
    if arbore is not None:
        if (arbore[stanga] is None and arbore[dreapta] is not None) or (arbore[stanga] is not None and arbore[dreapta] is None):
            return [arbore[cheie]] + copil(arbore[stanga]) + copil(arbore[dreapta])
        else:
            return copil(arbore[stanga]) + copil(arbore[dreapta])
    else:
        return []


print(f"Fiu afiseaza {copil(radacina)} ")


# ex2

def count_noduri(arbore):
    if arbore is not None:
        return 1 + count_noduri(arbore[stanga]) + count_noduri(arbore[dreapta])
    else:
        return 0


print(f"Noduri afiseaza {count_noduri(radacina)}")


