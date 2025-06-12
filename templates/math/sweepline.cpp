ll sl(vector< pair<ll, ll>> &s) {
  vector<pair<ll, ll>> e;  // eventos
  for (auto& i : s) {
    e.emplace_back(i.first, 1);
    e.emplace_back(i.second, -1);
  }
  // sort primero por posicion inicio, luego eventos finales (-1) tienen preferencia
  sort(e.begin(), e.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return (a.first == b.first) ? (a.second < b.second) : (a.first < b.first);
  });
  ll len = 0;  // vll res(n+2), cuantos enteros están cubiertos por i segmentos [1, n], n la cantidad max de segmentos
  ll sa = 0;  // segmentos activos
  ll lp = -1;  // ultima pos procesada
  for (auto& ev : e) {
    ll pos = ev.first, tipo = ev.second;
    if (sa > 0 && lp != -1) len += pos - lp;  // if (lp != -1 && pos > lp) res[sa] += pos - lp;
    sa += tipo;
    lp = pos;
  }
  return len;  // res.resize(n + 1); return vll(res.begin() + 1, res.end());
}