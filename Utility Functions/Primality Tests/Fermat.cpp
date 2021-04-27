// Recursive function to calculate greatest common divisor among two numbers (x,y)
int gcd (int x, int y) 
{  
    if (x < y) 
        return gcd (y, x); 
    else if (x%y == 0) 
        return y; 
    else return gcd (y, x%y);   
} 

// Iterative function to calculate/return (an)%p
int power (int a, unsigned int n, int p) 
{ 
    int result = 1;  
    a = a % p; // if a>=p. 
  
    while (n > 0) 
    {  
        if (n & 1) // if n is odd, multiply with the result.
            result = (result*a)%p; 
  
        n = n>>1; // if n is even, divide it by 2. 
        a = (a*a)%p; 
    } 
    return result; 
} 

// Function to check primality (using Fermat’s test) -
bool Primecheck (unsigned int n, int k) 
{ 
   if (n <= 1 || n == 4) return false; if (n <= 3) return true;
  
   while (k>0) // try k times
   {  
       int a = 2 + rand()%(n-4); // picks a random number in range (2,n-2), with n>4. 
   
       if (gcd (n, a)! = 1) // checks if a and n are co-prime with gcd function.
          return false; 
   
       if (power (a, n-1, n)! = 1) // using power function & Fermat’s little theorem.
          return false; 
  
       k--; 
    } 
  
    return true; 
} 
/* If selected number (say ‘n’) is prime, then function always returns true, else if n is composite than returns false with high probability. Higher value of k increases probability of correct result. 
In practical cases, Fermat’s test and multiple rounds of Miller-Rabin are used as primality tests for implementing RSA */
