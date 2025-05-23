const int MOD = 1e6;
const int MAX = 1000;
ll catalan[MAX];  // peligroso si MAX ~10^4, alternativa a C(2n, n) - C(2n, n-1)
void init() {
  catalan[0], catalan[1] = 1;
  for (int i = 2; i <= MAX; i++) {
    catalan[i] = 0;
    for (int j = 0; j < i; j++) {
      catalan[i] += (catalan[j] * catalan[i-j-1]) % MOD;
      if (catalan[i] >= MOD) catalan[i] -= MOD;  // if previene negativos
    }
  }
}