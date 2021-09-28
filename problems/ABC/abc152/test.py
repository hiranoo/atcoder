def modinv(a, m):
    b = m
    u = 1
    v = 0
    while b > 0:
        t = a / b
        a -= t * b
        tmp = a
        a = b
        b = tmp

        u -= t * v
        tmp = u
        u = v
        v = tmp

    u %= m
    if u < 0:
        u += m
    return u

def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if b == 0:
        return a
    return gcd(b, a%b)

def lcm(a, b, m):
    return (a%m * b%m * modinv(gcd(a,b), m)) %m

