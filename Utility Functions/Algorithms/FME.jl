function fastModularExponentiation(m, e, n::Integer)
    n > 0  || error("n must be positive")
    e >= 0 || error("e must be non-negative")
    r = 1
    while e > 0
        if (e & 1) > 0
            r = (r*m)%n
        end
        e >>= 1
        m = (m^2)%n
    end
    return r>0 ? r : r+n
end