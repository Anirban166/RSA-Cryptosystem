# Sieve of Eratosthenes based algorithm to find prime numbers up to a limit:
print("Enter an upper limit to find prime numbers upto, starting from one: ")
upperLimit = parse(Int, readline())
isPrime = [(i % 2) > 0 for i in 1:upperLimit]
isPrime[2] = true  # 2 is an exception, being the only even prime.
for num in 3:2:floor(Int, sqrt(upperLimit))
    isPrime[num] && foreach(i -> isPrime[i] = false, num * num:2 * num:upperLimit)
end
# Print all prime numbers from 1 to upperLimit:
foreach(i -> isPrime[i] && println(i), 2:upperLimit)