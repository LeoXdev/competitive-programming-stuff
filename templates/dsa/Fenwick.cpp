class Fenwick {
  public:
    Fenwick(int n) {
      this->n = n; this->arr.resize(n+1);
    }
    int sum(int k) const {
      int s = 0;
      while (k >= 1) {
        s += arr[k];
        k -= (k & -k);
      }
      return s;
    }
    void add(int k, int x) {
      while (k <= n) {
        arr[k] += x;
        k += (k & -k);
      }
    }
    int lowerbound(int k) const {  // primer índice con prefix >= k, o k-ésimo menor elemento en fenwick de frecuencias
      int i = 0;
      int m = (n & -n);
      while (m != 0) {
        int ni = i + m;
        if (ni <= n && arr[ni] < k) { k -= arr[ni]; i = ni; }
        m >>= 1;
      }
      return i + 1;
    }
  private:
    int n;
    vector<int> arr;
};
class Fenwick2D {
  public:
    Fenwick2D(int n, int m) {
      this->n = n+1; this->m = m+1;
      this->g.resize(this->n);
      for (int i = 0; i < n; i++) g[i].resize(this->m);
    }
    int sum(int x, int y) const {  // suma submatriz (1, 1) a (x, y)
      int res = 0;
      for (int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & -j)) res += g[i][j];
      return res;
    }
    int rangeSum(int x1, int y1, int x2, int y2) const {  // suma submatriz (x1, y1) a (x2, y2)
      return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
    }
    void add(int x, int y, int val) {
      for (int i = x; i <= n; i += (i & -i))
        for (int j = y; j <= m; j += (j & -j)) g[i][j] += val;
    }
  private:
    int n, m;
    vector<vector<int>> g;  // para llenar [x][y], al llamar a los métodos (y, x)
};