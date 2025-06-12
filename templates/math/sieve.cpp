int ng;  // no olvidar inicializar ng y hacer p.resize
vb p(ng+1, true);  // es i primo?, o vi d(ng + 1, 0); p/cantidad divisores
void sieve() {
  p[0] = 0; p[1] = 0;  // d[0] = 0; d[1] = 0;
  for (int i = 2; 1ll * i * i <= ng; i++)
  // for (int i = 1; i <= ng; i++) // p/divs, o i = 2 p/divs primos
    if (p[i]) for (int j = 1ll * i * i; j <= ng; j += i) p[j] = false;
    /*if (d[i] == 0) p/primos*/ // for (int j = i; j <= ng; j += i) d[j]++; p/divs
}