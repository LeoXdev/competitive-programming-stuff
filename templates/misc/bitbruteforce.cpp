// itera sobre los números, n <= 20~
for (int m = 0; m < (1 << n); m++) {
  // itera sobre los bits
  for (int i = 0; i < n; i++) {
    if (m & (1 << i)) {  // un bit está encendido
    } else { }
  }
}