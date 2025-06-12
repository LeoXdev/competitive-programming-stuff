ll gcd(ll a, ll b) {  // O(log min(a, b))
  while (b) { a %= b; swap(a, b); }
  return a;
}
ll lcm(ll a, ll b) { return 1ll * a / gcd(a, b) * b; }