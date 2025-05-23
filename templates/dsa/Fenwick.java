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