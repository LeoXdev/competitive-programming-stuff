// 2D BIT 0/1
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag,
  tree_order_statistics_node_update> OST;
const int N = 100'001;
OST bit[N];  // (fila, columna) = (y, x), NO hacer (x, y) como en ad-hocs
void insert(int x, int y) {
  for (int i = x; i < N; i += i & -i) bit[i].insert(mp(y, x));
}
void remove(int x, int y) {
  for (int i = x; i < N; i += i & -i) bit[i].erase(mp(y, x));
}
int query(int x, int y) {
  int ans = 0;
  for(int i = x; i > 0; i -= i & -i) ans += bit[i].order_of_key(mp(y+1, 0));
  return ans;
}