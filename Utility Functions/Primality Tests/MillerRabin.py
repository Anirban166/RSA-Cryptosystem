import random  
  
# Utility function to do modular exponentiation: (returns (x^y) % p)
def power(x, y, p):   
    res = 1;  
    x = x % p;  
    while (y > 0): 
        # If y is odd, multiply x with result 
        if (y & 1): 
            res = (res * x) % p; 
        # If even, divide it by 2: 
        y = y>>1;
        x = (x * x) % p; 
    return res; 
  
# This function is called for all k trials and it returns false if n is composite and/or probably prime:
# (Note: d is an odd number such that d*2<sup>r</sup> = n-1 for some r >= 1)
def millerRabin(d, n):  
    # Pick a random number in [2..n-2]: (n > 4) 
    a = 2 + random.randint(1, n - 4); 
    # Compute (a^d)%n:  
    x = power(a, d, n); 
    if (x == 1 or x == n - 1): 
        return True; 
    # Keep squaring x until d does not reach n-1 or until (x^2)%n is not 1 or n-1:
    while (d != n - 1): 
        x = (x * x) % n; 
        d *= 2; 
        if (x == 1): 
            return False; 
        if (x == n - 1): 
            return True; 
    # Return composite: 
    return False; 
  
# This function returns false if n is composite and returns true if n is probably prime:
# (Note: k is an input parameter that determines the accuracy level. Higher value of k indicates more accuracy)
def isPrime(n, k): 
    if (n <= 1 or n == 4): 
        return False; 
    if (n <= 3): 
        return True; 
    d = n - 1; 
    while (d % 2 == 0): 
        d //= 2; 
    for i in range(k): 
        if (miillerTest(d, n) == False): 
            return False; 
    return True; 
 
k = 4
x = int(1e+2)  
print("All primes smaller than ", x, ": "); 
for n in range(1, x): 
    if (isPrime(n, k)): 
        print(n , end = " "); 