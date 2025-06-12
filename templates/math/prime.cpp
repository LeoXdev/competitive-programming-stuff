bool prime(ll n) {
  if (n <= 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; 1ll * i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
for (int i = 1; 1ll * i * i <= n; i++) if (n % i == 0) {  // divisores de n
  if (1ll * i * i == n) res += i; else res += i + (n/i);  // o push_back
}