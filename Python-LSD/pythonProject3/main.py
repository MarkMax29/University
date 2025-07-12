# exercitiul 4b)
def nr_cif(n):
    if n != 0:
        return 1 + nr_cif(n // 10)
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
def pare(t):
    if t == 0:
        return 1
    if t != 0:
        if (t % 10) % 2 == 0:
            return 1 + pare(t // 10)
        else:
            return pare(t // 10)


print(pare(123456))


# exercitiul 5

def exp(a, n):
    if n == 0:
        return 1
    if n != 0:
        return a * exp(a, n - 1)


print(exp(2, 4))

#exercitiul 9
def interval(min_value, max_value):
    if min_value <= max_value:
        print(min_value, end=" ")
        return interval(min_value + 1, max_value)


print(interval(5, 15))
