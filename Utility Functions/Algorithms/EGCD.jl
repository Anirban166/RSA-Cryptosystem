function egcd{T <: Integer}(a::T, b::T)
  if mod(a, b) == zero(T)
    return [zero(T), one(1)]
  else
    x, y = egcd(b, mod(a, b))
    return [y, x - (y * fld(a, b))]
  end
end