def myPow(a, n, m):
    if n == 0:
        return 1
    if n % 2 == 0:
        return myPow((a * a) % m, n / 2, m)
    return a * myPow(a, n - 1, m) % m
