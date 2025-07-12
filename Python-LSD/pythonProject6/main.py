import functools
def adauga_pereche(pereche, dictionar):
    cheie, valoare = pereche
    dictionar[cheie] = valoare

    return dictionar

def filter_dict(dictionar, conditie):
    return functools.reduce(lambda dict_nou, pereche: adauga_pereche(pereche, dict_nou) if conditie(pereche[1]) else dict_nou, dictionar.values(), {})

print(filter_dict({'a': 5, 'b': 7, 'c': 1}, lambda x: x >= 5))
