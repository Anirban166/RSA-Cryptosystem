function extendedEuclideanAlgorithm(a, b)
    if b == 0
        return (a, 1, 0)
    end
    gcd, x1, y1 = extendedEuclideanAlgorithm(b, a % b)
    x = y1
    y = x1 - floor(a / b) * y1
    return gcd, x, y
end