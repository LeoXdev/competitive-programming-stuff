from fractions import Fraction  # Fraction maneja divisiones de numeros enormes
def bincoe(n, k):  # el resultado hay que castearlo f"{float(res):.12f}"
  if k < 0 or k > n:
    return Fraction(0)
  if k == 0 or k == n:
    return Fraction(1)
  if k > n - k:
    k = n - k
  res = 1
  for i in range(k):
    res *= Fraction(n - i)
    res /= Fraction(i + 1)
  return res