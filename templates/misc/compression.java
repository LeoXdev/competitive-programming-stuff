public class Main {
  public static void main(String[] args) {
    // TreeMap
    ArrayList<Integer> b = new ArrayList<>(a);  // a será sobreescrito
    Collections.sort(b);
    ArrayList<Integer> c = new ArrayList<>();
    c.add(b.get(0));
    for (int i = 1; i < b.size(); i++) if (!b.get(i).equals(b.get(i-1))) c.add(b.get(i));
    TreeMap<Integer, Integer> m = new TreeMap<>();
    for (int i = 0; i < c.size(); i++) m.put(c.get(i), i);
    ArrayList<Integer> vo = new ArrayList<>(c); // recuperar: vo.get(comprimido)
    for (int i = 0; i < a.size(); i++) a.set(i, m.get(a.get(i)));

    // Pair
    ArrayList<Pair<Integer, Integer>> p = new ArrayList<>();  // a será sobreescrito
    for (int i = 0; i < a.size(); ++i) p.add(new Pair<>(a.get(i), i));
    Collections.sort(p);  // ordena pares de acuerdo al primer valor
    int n = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (i > 0 && !p.get(i-1).first.equals(p.get(i).first)) n++;
      a.set(p.get(i).second, n);  // +1 a n si trabajamos con fenwick/segtree
    }
  }
}
class Pair<F extends Comparable<F>, S extends Comparable<S>> implements Comparable<Pair<F, S>> {
  public F first;
  public S second;
  public Pair(F first, S second) { this.first = first; this.second = second; }
  @Override
  public int compareTo(Pair<F, S> other) {
    int c = this.first.compareTo(other.first);
    if (c != 0) return c;
    // si ambos F son iguales
    return this.second.compareTo(other.second);  // orden asc en S, cambiar other por this para desc
  }
  @Override
  public String toString() { return "f = " + this.first + ", s = " + this.second + "."; }
}