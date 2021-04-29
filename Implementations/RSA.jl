#= Install the primes package: (if unavailable)
import Pkg; Pkg.add("Primes") =#
using Primes

# Public key: (e,n)
struct PublicKey
    n::Integer
    e::Integer
end

# Private key: (d,n)
struct PrivateKey
    n::Integer
    d::Integer    
end

function keyGenerator(p::Integer, q::Integer, e::Integer)
    # Basic corner cases:    
    isprime(p) || error("p must be a prime number")
    isprime(q) || error("q must be a prime number")
    e > 0 || error("e must be positive")
    # Computing Euler's totient:
    phi = (p - 1) * (q - 1)
    # Computing greatest common divisor and Bézout coefficients (i.e. u and v, such that u*e + u*phi = gcd(e,phi)):
    (g, u, v) = gcdx(e,phi)
    # If gcd(e,phi)!=1, they aren't coprime: 
    g == 1 || error("phi(n) and e must be coprime")
    # Computing private exponent d based on (+ve)/(-ve) value of u through a ternary operator:
    u < 0 ? d = (u % phi) + phi : d = u % phi
    # Computing n as the product of the two entered primes and returning the computed public and private key components: 
    n = p * q
    return PublicKey(n, e), PrivateKey(n, d)
end

# Encryption function:
function encrypt(m::Integer, k::PublicKey)
    0 <= m || error("m must be non-negative")
    m < k.n || error("m is too large")
    return powermod(m, k.e, k.n)
end

# Decryption function:
function decrypt(c::Integer, k::PrivateKey)
    0 <= c || error("c must be non-negative")
    c < k.n || error("c is too large")
    return powermod(c, k.d, k.n)
end

print("Enter a prime number: ")
p = parse(Int, readline())
print("Enter another prime number: ")
q = parse(Int, readline())
print("Enter public key exponent: ")
e = parse(Int, readline())
(publicKey, privateKey) = keyGenerator(p, q, e)
println("Public key (n,e) = ($(publicKey.n),$(publicKey.e)); (to be shared)")
println("Private key (n,d) = ($(privateKey.n),$(privateKey.d)); (to be kept with oneself)")
println("Enter an integer to encrypt:")
m = parse(Int, readline())
println("Original integer: $m")
c = encrypt(m, publicKey)
println("Encrypted integer: $c")
println("Decrypted integer: $(decrypt(c,privateKey))")