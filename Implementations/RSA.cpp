#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
using l = long long int;
#define S 100

// Globally passed variables:
l p, q,      // primes
  n,        // n = pq
  t,       // toutient
  flag,   // 1/0
  e[S],  // public exponent e
  d[S], // private exponent d
  temp[S], m[S], en[S];

char msg[S];

// Functions:
bool primecheck(l); // Check if(prime)
void ce();         // Calculate exponent e
l cd(l);          // Calculate exponent d (return value)
void encrypt();  // Encrypt plaintext
void decrypt(); // Decrypt ciphertext

bool primecheck(l var) 
{
	int i, j = sqrt(var);
	for (i = 2; i <= j; ++i)
	if (var % i == 0)
			return false;
	return true;
}

void ce()
{
     int k = 0;
     for (int i = 2; i < t; i++)
     {
	 if (t % i == 0) continue;
	 flag = primecheck(i);
	 if (flag == 1 && i != p && i != q)
	 {
	     e[k] = i;
	     flag = cd(e[k]);
	     if (flag > 0)
	     {
		d[k] = flag;
		k++;
	     }
	     if (k == 99) // (S-1)
	     break;
	 }
     }
}

l cd(l x) 
{
     long int k = 1;
     while (true)
     {
	 k += t;
	 if (k % x == 0) return (k / x);
     }
}

void encrypt()
{
	l pt, ct, key = e[0], k, len;
	int i = 0;
	len = strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (int j = 0; j < key; j++)
		{
			k *= pt;
			k %= n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	std::cout << "Encrypted message:\n";
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
}

void decrypt() 
{
	l pt, ct, key = d[0], k;
	int i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (int j = 0; j < key; j++)
		{
			k *= ct;
			k %= n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	std::cout << "Decrypted message:\n";
	for (int i = 0; m[i] != -1; i++)
		printf("%c", m[i]);
}

int main()
{   
    do 
    {
	   std::cout << "Enter two primes (p,q for Euler's totient to be taken as (p-1)(q-1)):\n";
	   std::cin >> p >> q;
	   if(primecheck(p) && primecheck(q)) break;
	   else std::cout << "Wrong input; Please enter prime numbers.\n";
    } while(1);    

	std::cout << "Enter message for encryption:\n";
	fflush(stdin);
	std::cin >> msg;
	for (int i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
		
	n = p * q;
	t = (p - 1) * (q - 1);
	ce();
	encrypt();
	decrypt();
	return 0;
}
