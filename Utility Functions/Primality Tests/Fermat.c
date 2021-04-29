#include <stdio.h>
#include <stdlib.h>
#define ll long long

ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
        {
            if (exponent % 2 == 1)
                x = (x * y) % mod;
            y = (y * y) % mod;
            exponent = exponent / 2;
        }
    return x % mod;
}

int fermat(ll p, int iterations)
{
    int i;
    if (p == 1)
        return 0;
    for (i = 0; i < iterations; i++)
        {
            ll a = rand() % (p - 1) + 1;
            if (modulo(a, p - 1, p) != 1)
                return 0;
        }
    return 1;
}

int main()
{
    int iterations = 50;
    ll num;
    printf("Enter integer to test primality: ");
    scanf("%lld", &num);
    if (Fermat(num, iterations) == 1)
        printf("%lld is prime ", num);
    else
        printf("%lld is not prime ", num);
    return 0;
}