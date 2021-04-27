function isCoprime(a, b)
    if b == 0
        return a == 1
    end
    return isCoprime(b, a % b)
end