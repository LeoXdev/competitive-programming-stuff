public class Main {
  static int readInt() throws Exception {
    int c = System.in.read(), v = 0, s = 1;  // se puede cambiar int por long
    while (c <= 32) c = System.in.read();
    if (c == '-') { s = -1; c = System.in.read(); }
    while (c > 32) {
      v = v * 10 + (c - '0');
      c = System.in.read();
    }
    return v * s;
  }
  static char readChar() throws Exception {
    int c = System.in.read();
    while (c <= 32) c = System.in.read();
    return (char) c;
  }
}