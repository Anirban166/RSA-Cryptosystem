function isPrime(n)
    for i = 2:Int(floor(sqrt(n)))
        if n % i == 0; 
            return false
        end
    end
    return true
end