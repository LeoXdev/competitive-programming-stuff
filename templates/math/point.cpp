typedef long double T;
T EPS = 1e-9;
struct pt {
  T x, y;
  pt operator+(pt p) { return {x+p.x, y+p.y}; }
  pt operator-(pt p) { return {x-p.x, y-p.y}; }
  pt operator*(T d) { return {x*d, y*d}; }
  pt operator/(T d) { return {x/d, y/d}; }
  bool operator==(const pt& o) const { return x == o.x && y == o.y; }
  bool operator!=(const pt& o) const { return !(*this == o); }
};
// transformaciones
pt translate(pt v, pt p) { return p+v; }
pt scale(pt c, double factor, pt p) { return c + (p-c)*factor; }
pt rot(pt p, double a) { return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)}; }
// dot product
T dot(pt v, pt w) { return v.x*w.x + v.y*w.y; }
bool isPerp(pt v, pt w) { return dot(v,w) == 0; }
// ángulo entre dos vectores
double abs(pt p) { return sqrt((double)(p.x * p.x + p.y * p.y)); }
double angle(pt v, pt w) {
  double cosTheta = dot(v,w) / abs(v) / abs(w);
  return acos(max(-1.0, min(1.0, cosTheta)));
}
// ángulo entre dos vectores, C++17
//double angle(pt v, pt w) { return acos(clamp(dot(v,w) / abs(v) / abs(w), -1.0, 1.0)); }
// cross product
T cross(pt v, pt w) { return v.x*w.y - v.y*w.x; }
// orientación
// + -> c a la izq de AB
// - -> c a la der de AB
// 0 -> ABC colineales
T orient(pt a, pt b, pt c) { return cross(b-a,c-a); }
bool isConvex(vector<pt> p) {
  bool hasPos=false, hasNeg=false;
  for (int i=0, n=p.size(); i<n; i++) {
    int o = orient(p[i], p[(i+1)%n], p[(i+2)%n]);
    if (o > 0) hasPos = true;
    if (o < 0) hasNeg = true;
  }
  return !(hasPos && hasNeg);
}
// polar sort, sentido antihorario
void polarSort(vector<pt> &v) {
  int n = v.size();
  pt centroid = {0, 0};
  for (auto& p : v) centroid = centroid + p;
  centroid = centroid / T(n);

  sort(v.begin(), v.end(), [&](pt a, pt b) {
    pt va = a - centroid;
    pt vb = b - centroid;
    T crossProd = cross(va, vb);
    if (abs(crossProd) < EPS) // si son colineales, ordenar por distancia al centro
      return va.x * va.x + va.y * va.y < vb.x * vb.x + vb.y * vb.y;
    return crossProd > 0; // sentido antihorario
  });
}
// O(log n), deben estar ordenados los puntos en sentido antihorario
bool pointInConvexPolygon(const vector<pt>& poly, pt point) {
  int n = poly.size();
  if (n < 3) return false;

  if (orient(poly[0], poly[1], point) < 0 || orient(poly[0], poly[n-1], point) > 0) return false;
  int lo = 1, hi = n - 1;
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (orient(poly[0], poly[mid], point) >= 0) lo = mid;
    else hi = mid;
  }
  return orient(poly[lo], poly[lo + 1], point) >= 0;
}