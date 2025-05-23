int dp[20][200][2];  // max digitos, suma maxima, tight // !! [2, n-1]
int f(int i, int s, bool t) {
  // caso base: ya se formó todo el numero
  if (i == str.size()) return s == 5;  // !! (solo lo de adentro del if, no la condicion)
  // caso: estado ya calculado
  if (dp[i][s][t] != -1) return dp[i][s][t];

  int res = 0;
  int tope = t ? (str[i] - '0') : 9;  // tight hace su chamba
  for (int d = 0; d <= tope; d++) {
    bool nt = t && (d == tope);
    res += f(i + 1, s + d, nt);  // !! (solo del segundo al n-1 parametro)
  }
  return dp[i][s][t] = res;  // establecer estado, res = "números cumpliendo la condición"
}
int digitdp(string r) {  // [0, r]
  str = r;
  memset(dp, -1, sizeof(dp));
  return f(0, 0, 1);
}
string subtractOne(string s) {
  for (int i = s.size() - 1; i >= 0; --i) {
    if (s[i] > '0') { s[i]--; break; }
    s[i] = '9';
  }
  if (s[0] == '0') s = s.substr(1);
  return s;
}