#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long mulmod(long long a, long long b, long long mod)
{
    long long x = 0,y = a % mod;
    while (b > 0)
        {
            if (b % 2 == 1)
                {
                    x = (x + y) % mod;
                }
            y = (y * 2) % mod;
            b /= 2;
        }
    return x % mod;
}

long long modulo(long long base, long long exponent, long long mod)
{
    long long x = 1;
    long long y = base;
    while (exponent > 0)
        {
            if (exponent % 2 == 1)
                x = (x * y) % mod;
            y = (y * y) % mod;
            exponent = exponent / 2;
        }
    return x % mod;
}

int Miller(long long p,int iterations)
{
    int i;
    long long s;
    if (p < 2)
        {
            return 0;
        }
    if (p != 2 && p % 2==0)
        {
            return 0;
        }
    s = p - 1;
    while (s % 2 == 0)
        {
            s /= 2;
        }
    for (i = 0; i < iterations; i++)
        {
            long long a = rand() % (p - 1) + 1, temp = s;
            long long mod = modulo(a, temp, p);
            while (temp != p - 1 && mod != 1 && mod != p - 1)
                {
                    mod = mulmod(mod, mod, p);
                    temp *= 2;
                }
            if (mod != p - 1 && temp % 2 == 0)
                {
                    return 0;
                }
        }
    return 1;
}

int main()
{
    int iterations;
    long long num;
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);
    printf("Enter an integer for primality testing: ");
    scanf("%lld", &num);
    if (Miller(num, iterations))
        printf("\n%lld is prime\n", num);
    else
        printf("\n%lld is not prime\n", num);
    return 0;
}
