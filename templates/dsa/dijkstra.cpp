int main() {
  //vll d(n, LLONG_MAX);  normal
  vector<vll> d(n, vll(k+1, LLONG_MAX));  // !! dp, d[v][z] = menor distancia para llegar al nodo v, <con x condicion/es>
  //vector<int> p(n, -1);  // nodo previo p/c/nodo
  // inicio, se requiere: vector<vector<pair<int, int>>> g(n);
  using state = array<ll, 3>;  // !! distancia actual, nodo, ... x condicion
  priority_queue<state, vector<state>, greater<state>> pq;

  int s = 0;  // nodo inicio
  d[s] = 0;  // p[s] = -1
  pq.push({0, s});
  while (!pq.empty()) {
    const auto [da, v, k_u] = pq.top();  // distancia actual, nodo
    pq.pop();
    if (da != d[v]) continue;  // evita procesar nodos con distancias obsoletas, alternativa >
    for (const pair<int, int> &u : g[v]) {  // u.first = vecino, u.second = peso p/llegar al vecino
      if (da + u.second < d[u.first]) {  // se encontró una mejor forma de llegar al nodo u
        //p[u.first] = v;  // nodo previo que causó mejora en la distancia
        d[u.first] = 1ll * da + u.second;
        pq.push({d[u.first], u.first});
      }
    }
  }
}