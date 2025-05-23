const int MOD = 1e9+7;
const int MAX = 1e6+1;
ll fact[MAX], inv_fact[MAX];
ll pow_mod(ll x, ll n, ll m) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = 1ll * (res * x) % m;
    n >>= 1;
    x = 1ll * (x * x) % m;
  }
  return res;
}
void init() {
  fact[0] = 1;
  for (int i = 1; i < MAX; i++) fact[i] = 1ll * (fact[i - 1] * i) % MOD;
  inv_fact[MAX - 1] = 1ll * pow_mod(fact[MAX - 1], MOD - 2, MOD);
  for (int i = MAX - 2; i >= 0; i--) inv_fact[i] = 1ll * (inv_fact[i + 1] * (i + 1)) % MOD;
}
ll bincoe(ll n, ll k) {
  if (k < 0 || k > n) return 0;
  return 1ll * fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}