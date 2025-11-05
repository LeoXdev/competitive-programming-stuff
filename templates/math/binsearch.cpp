ll binsearch() {  // lowerbound en funcion
  ll l = 1;  // mejor caso
  ll r = 1e9;  // peor caso
  ll res = -1;
  while (l <= r) {
    ll m = l + (r -  l) / 2;
    if (f(m)) {  // se cumplio la función, buscar un m más pequeño aún
      res = m;
      r = m - 1;
    } else {
      l = m + 1;  // buscar más arriba
    }
  }
  return res;
}
int uqc(vi &a, int x) {  // indice del ultimo valor <= x
  int l = 0;  // "mejor" caso, indice 0 es el ultimo num mas grande que x
  int r = a.size() - 1;  // "peor" caso, indice last es el ultimo num mas grande que x
  int res = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] <= x) {
      // a[m] es menor, buscar un indice aún mayor
      res = m;
      l = m + 1;
    } else {
      // a[m] es mayor, buscar un valor menor
      r = m - 1;
    }
  }
  return res;
}
ll binsearch() {  // upperbound

}

int bs(vi &a, int x) {  // retorna indice del x a buscar o -1
  int l = 0;  // "mejor" caso, x esta en indice 0
  int r = a.size() - 1;  // "peor" caso, x esta en indice size()-1
  //int res = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] == x) return m;
    if (a[m] > x) {
      // buscar mas abajo
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return -1;
}