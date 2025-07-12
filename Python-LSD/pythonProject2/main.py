# exercitiul 4b)
def nr_cif(n):
    if n != 0:
        return 1 + nr_cif(n //10 )
    else:
        return 0


print(nr_cif(23456789))


# execitiul 4c)
def maxi(x):
    if x < 10:
        return x
    else:
        return max(x % 10, maxi(x // 10))


print(maxi(8374693113))


# exercitiul 4d)
def par(t) :
    if t != 0:
        if t % 2 == 0:
            return 1 + par(t // 10)
        else:
            return par(t // 10)

print(par(123456))
