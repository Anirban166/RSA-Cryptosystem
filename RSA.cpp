#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
using l = long long int;

// Variables:
l p, q, n, t, flag, e[100], d[100], temp[100], j, m[100], en[100], i;
char msg[100];

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
	for (i = 2; i < t; i++)
	{
		if (t % i == 0)
			continue;
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
			if (k == 99)
				break;
		}
	}
}

l cd(l x) 
{
	long int k = 1;
	while (2==2)
	{
		k = k + t;
		if (k % x == 0)
			return (k / x);
	}
}

void encrypt()
{
	l pt, ct, key = e[0], k, len;
	i = 0;
	len = strlen(msg);
	while (i != len)
	{
		pt = m[i];
		pt = pt - 96;
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * pt;
			k = k % n;
		}
		temp[i] = k;
		ct = k + 96;
		en[i] = ct;
		i++;
	}
	en[i] = -1;
	std::cout << "Encrypted Message :\n";
	for (i = 0; en[i] != -1; i++)
		printf("%c", en[i]);
}

void decrypt() 
{
	l pt, ct, key = d[0], k;
	i = 0;
	while (en[i] != -1)
	{
		ct = temp[i];
		k = 1;
		for (j = 0; j < key; j++)
		{
			k = k * ct;
			k = k % n;
		}
		pt = k + 96;
		m[i] = pt;
		i++;
	}
	m[i] = -1;
	std::cout << "Decrypted Message :\n";
	for (i = 0; m[i] != -1; i++)
		printf("%c", m[i]);
}

int main()
{   
	std::cout << "Enter two primes (p,q for Euler's totient to be taken as (p-1)(q-1)) :\n";
	std::cin >> p;
	flag = primecheck(p);
	if (flag == 0)
	{
		std::cout << "Wrong input!\n";
		exit(1);
	}
	std::cout << "Enter another prime :\n";
	std::cin >> q;
	flag = primecheck(q);
	if (flag == 0 || p == q)
	{
		std::cout << "Wrong input!\n";
		exit(1);
	}
	std::cout << "Enter message for encryption :\n";
	fflush(stdin);
	std::cin >> msg;
	for (i = 0; msg[i] != '\0'; i++)
		m[i] = msg[i];
	n = p * q;
	t = (p - 1) * (q - 1); // Calcualting Euler's totient.
	ce();
	std::cout << "Possible values of exponents 'e' and 'd' are :\n";
	for (i = 0; i < j - 1; i++)
		std::cout << e[i] << "\t" << d[i] << "\n";
	encrypt();
	decrypt();
	return 0;
}
