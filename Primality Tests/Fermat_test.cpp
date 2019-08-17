(1) Fermat's primality test - (compiled in GNU GCC, IDE: Dev C++) 
(1.a) Recursive function to calculate greatest common divisor among two numbers (x,y) -
int gcd (int x, int y) 
{ 
    if (x < y) 
        return gcd (y, x); 
    else if (x%y == 0) 
        return y; 
    else return gcd (y, x%y);   
} 

(1.b) Iterative function to calculate/return (an)%p -
int power (int a, unsigned int n, int p) 
{ 
    int result = 1;  
    a = a % p; // if a>=p. 
  
    while (n > 0) 
    {  
        if (n & 1) //if n is odd, multiply with result.
            result = (result*a)%p; 
  
        n = n>>1; // if n is even, n=n/2. 
        a = (a*a)%p; 
    } 
    return result; 
} 

(1.c) Function to check primality (using Fermat’s test) -
bool Primecheck (unsigned int n, int k) 
{ 
   if (n <= 1 || n == 4) return false; if (n <= 3) return true; //exception cases.
  
   while (k>0) //Try k times.
   {  
       int a = 2 + rand()%(n-4); //picks a random number in range (2,n-2), with n>4. 
   
       if (gcd (n, a)! = 1) //checks if a and n are co-prime with gcd function.
          return false; 
   
       if (power (a, n-1, n)! = 1) //using power function & Fermat’s little theorem.
          return false; 
  
       k--; 
    } 
  
    return true; 
} 
// If selected number (say ‘n’) is prime, then function always returns true, else if n is composite than returns false with high probability. Higher value of k increases probability of correct result. 

In practical cases, Fermat’s test and multiple rounds of Miller-Rabin are used as primality tests for implementing RSA, but for simplicity and ease of coding, I have used the standard prime check test used in school/college-level programming for the RSA implementation below -
