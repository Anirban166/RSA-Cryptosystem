function gcd(a, b)
    if b == 0
        return a
    end
    return gcd(b, a % b)
end