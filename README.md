# RSA-Cryptosystem

Introduction:
-------

RSA, as named after the surnames of three MIT professors (Rivest-Shamir-Adleman) who discovered it, is one of the first public key cryptosystems which is being widely used and accepted till date as a good encryption scheme. Here, the encryption key and decryption key are public and private respectively. 
An RSA user creates a public key based on the product of two large prime numbers and an auxiliary exponent value which is shared, and a private key based on the public key values. The two primes are kept secret. The process and its feasibility is discussed below.

Steps Involved in RSA (key generation):
-------

(1) First, we choose two distinct prime numbers, say p and q. (random primes, preferably big to score a decent level of security)

-> Can be generated using a primality test.

-> Fermat’s test can be used, though practically Miller Rabin’s test is more sought after.

(2) n=p*q, which is the modulus of both the keys.

(3) Then we calculate Euler’s totient, ϕ(n) = (p-1)*(q-1). 

(4) Then we choose public key e such that e>2 and co-prime to totient i.e., gcd(e,totient) must be equal to 1.

-> In most cases e is a small number. 

(5) Then we choose private key d such that it satisfies the equation or e*d mod ϕ(n)=1. 

-> d is the multiplicative inverse of e modϕ(n).

-> Public key comprises of (e,n) and private key comprises of (d).

-> As e is much smaller than d, encrypting a message using RSA is much faster than decrypting it. 

(6) Ciphertext is calculated using the equation c=memodn where m is the message to be encrypted.

(7) With the help of c and d thus obtained, we decrypt the message using m=c<sup>d</sup>modn.

Explanation:
-------

The Euler’s totient φ(n) of a positive integer n greater than 1 is defined to be the number of positive integers less than n that are coprime (only positive divisor is 1 or gcd is 1 between two numbers) to n. (φ(1) is defined to be 1)
when n is prime, ϕ (n)=n-1, as in the case of Fermat’s theorem.
Plaintext and ciphertext are integers between 0 and n-1 for some n.

Encryption and decryption are of the following form, for some plaintext M and ciphertext C:
C = Me(mod n) 
M = Cd(mod n) = (Me)d(mod n) = Med(mod n)

Each communicating entity has one public key (e,n) or private key (d,n) pair, where e and d are each the multiplicative inverse (modϕ(n)) of the other. 

=> e and d are inverses (modϕ(n)), or ed ≡ 1 (modϕ(n))

=> ed = 1 + kϕ(n), for some k.

=> Med(mod n) =M 1 + kϕ(n) (mod n) = M1 x (M ϕ(n))k (mod ϕ(n)) = M1 x 1k (mod n) = M. (Euler’s theorem)

Therefore, to decrypt a ciphertext C = Med(mod n), we only need to calculate Cd(mod n) because we know C= Me(mod n) => Cd(mod n)= Med(mod n) => Cd(mod n)=M. (since Med(mod n) = M)

Viability:
-------

The RSA cryptosystem is based on the theorem which implies that the inverse of the function a->aemodn (where e is the public encryption exponent) is the function b->bdmodn, (where d is the private decryption exponent) which gives the difficulty of computing ϕ(n) without knowing the factorization of n, thus the difficulty of computing d arises too. 
This can only be solved by factorizing n (since every number is essentially a product of primes) and only the owner of the private key knows the factorization (primes p,q whose product yields n). This ‘factoring problem’ is the security point, with more chances of the encryption to be secure for large values of n, or for large primes considered. Only n being publicly disclosed, along with the given difficulty to factor large numbers (it is computationally infeasible to factor a large value of n to get d) gives the guarantee that no one else knows the factorization and the encrypted message, thus making it viable.

Practical Implementation:
-------

The written code works well for small primes but considering a deeper level of security, preferable prime length for the 2 primes considered (p,q) ranges to around primes of 2048 bits (211) which result in values (n) greater than 4096 bits upon their multiplication (p*q). This ensures a tight encryption which is impossible to decrypt with massive computing resources even with a large span of time allotted.

Hence RSA is quite feasible, apart from its downsides like being much slower than symmetric cryptosystems.

-------
All of this has been credited in my paper on RSA and elliptic curve cryptography as a research intern in IITG. 

-------
Summary Addon for quick encryption/decryption: (22/07/19)

:lock:Encryption
-------
Input: RSA public key (n,e), plaintext m ∈ [0,n-1] |
Output: Ciphertext c, (Compute c = Me(mod n), return c).

:unlock:Decryption
-------
Input: RSA public key (n,e), RSA private key d, ciphertext c |
Output: Plaintext m,  (Compute m = cd(mod n), return m). 
