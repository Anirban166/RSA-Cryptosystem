# import openssl:
library(openssl)
# C equivalent: (since most algorithms have reference implementations based on the C variant)
# #include <openssl/rsa.h>

# The main function we are concerned with is rsa_keygen(), which generates a random private key of specified bits.
private_key <- rsa_keygen(bits = 1024)
# Now that we got our 1024-bit private key, we can extract the public key with the same number of bits:
public_key <- private_key$public_key

# Encryption & Decryption can be followed with rsa_encrypt() and rsa_decrypt() functions:
message <- charToRaw("Alias{Anirban166}: Raven")
ciphertext <- rsa_encrypt(message, public_key)
rawToChar(rsa_decrypt(ciphertext, private_key)) # prints out the message

# To see whats underneath, (such as the numbers use for the key) we can unfold the private key:
private_key$data
# It includes the 1024-bit prime numbers included for key generation (p,q), their product n or the Euler's totient and the private & public exponents (e,d).
# On the other hand, the public key only contains the public & private exponents (e,d) and the product of the primes (n), making it impossible to decrypt the message or find the two numbers (p,q).

# For encrypting the plaintext message into ciphertext, we need to convert it into an integer:
plain.text <- bignum(charToRaw("Alias{Anirban166}: Raven"))
# Extract the Euler's totient and the exponent e (public) from the public key:
n <- public_key$data$n
e <- public_key$data$e
# Calculate the ciphertext:
cipher.text <- (m ^ e) %% n
# To obtain the exponent d (private), we need to use the private key:
d <- private_key$data$d
# Since the value of ciphertext raised to the power of d is extremely large, we will need to use bignum_mod_exp() function in order to decrypt the ciphertext:
decrypted.message <- bignum_mod_exp(cipher.text, d, n)
# Again, we need to convert the result into characters to obtain the string we sent as a message:
rawToChar(decrypted.message) # prints out the message


