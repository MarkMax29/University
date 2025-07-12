import functools
def f(x):
    if x>3:
        return True
    else:
        return False
def subset(mult,f):
    return functools.reduce(lambda mult_nou,el: mult_nou|{el} if f(el) else mult_nou,mult,set())
print(subset({1,3,4,8,9},f))