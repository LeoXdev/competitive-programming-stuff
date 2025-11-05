class Fenwick {
  private int[] arr;
  private int n;
  public Fenwick(int n) {
    this.n = n;
    arr = new int[n + 1];
  }
  public int sum(int k) {
    int s = 0;
    while (k >= 1) {
      s += arr[k];
      k -= Integer.lowestOneBit(k);
    }
    return s;
  }
  public void add(int k, int x) {
    while (k <= n) {
      arr[k] += x;
      k += Integer.lowestOneBit(k);
    }
  }
  public int lowerbound(int k) {  // primer indice con prefix >= k, o elemento k-th en fenwick de frecuencias
    int i = 0;
    int m = Integer.highestOneBit(n);
    while (m != 0) {
      int ni = i + m;
      if (ni <= n && arr[ni] < k) { k -= arr[ni]; i = ni; }
      m >>= 1;
    }
    return i + 1;
  }
}
class Fenwick2D {
  private int[][] tree;  // llenar como matrices normales [x][y], llamar metodos [y][x]
  private int n, m;
  public Fenwick2D(int n, int m) {
    this.n = n; this.m = m;
    tree = new int[n + 1][m + 1];
  }
  public int sum(int x, int y) {  // suma submatriz (1, 1) a (x, y)
    int res = 0;
    for (int i = x; i > 0; i -= Integer.lowestOneBit(i))
      for (int j = y; j > 0; j -= Integer.lowestOneBit(j)) res += tree[i][j];
    return res;
  }
  public int rangeSum(int x1, int y1, int x2, int y2) {  // suma submatriz (x1, y1) a (x2, y2)
    return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
  }
  public void add(int x, int y, int val) {
    for (int i = x; i <= n; i += Integer.lowestOneBit(i))
      for (int j = y; j <= m; j += Integer.lowestOneBit(j)) tree[i][j] += val;
  }
}