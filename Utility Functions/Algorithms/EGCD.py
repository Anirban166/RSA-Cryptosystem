def egcd(a, b):
    if a == 0:
        return b, 0, 1 
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y

def modularInverse(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('Modular inverse does not exist!')
    else:
        return x % m