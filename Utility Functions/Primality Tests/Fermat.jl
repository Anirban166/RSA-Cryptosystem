# Fermat's primality test: (Test for a number to be prime or not, based on Fermat's little theorem)
function fermatPrimalityTest(n, iterations = 5)
    if n < 4
        return n == 2 || n == 3
    end

    for i = 1:iterations
        a = rand(2:(n - 2), 1)[1]
        if ((BigInt(a) ^ (n - 1)) % n) != 1
            return false
        end
    end
    return true
end

# Fermat's factorization: (Representation of an odd integer as the difference of two squares)
function fermatFactorization(n::Int64)
    a = ceil(sqrt(n))
    b2 = a * a - n
    b = round(sqrt(b2))
    while (b * b != b2)
        a = a + 1
        b2 = a * a - n
        b = round(sqrt(b2))
    end
    return Int64(a - b)
end