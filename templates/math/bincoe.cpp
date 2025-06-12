ll bincoe(int n, int k) {
  if (k < 0 || k > n) return 0;  // no todos los problemas requieren esto
  if (k == 0 || k == n) return 1;
  if (k > n - k) k = n - k;

  ll res = 1;
  for (int i = 0; i < k; i++) {
    res *= (n - i);
    res /= i + 1;  // comentar p/perms
  }
  return res;
}