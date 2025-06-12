ld tersearch() {  // funciones continuas
  ld l = 0;
  ld r = 1e9;
  for (int i = 0; i < 300; i++) {
    ld m1 = l + (r - l) / 3;
    ld m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) l = m1;  // < maximo, > minimo
    else r = m2;
  }
  return f(l);
}
ll tersearch() {  // funciones discretas
  int l = -1;
  int r = 1e9;
  while (r - l > 1) {
    int m = (r + l) >> 1;
    if (f(m) > f(m+1)) r = m;  // < maximo, > minimo
    else l = m;
  }
  return l + 1;
}