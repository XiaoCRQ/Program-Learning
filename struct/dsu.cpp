#include "../t_head.h"
const ll N = 2e5 + 5;
ll pa[N], sz[N];
ll find(ll x) { return pa[x] == x ? x : pa[x] = find(pa[x]); }
void unite(ll x, ll y) {
  x = find(x), y = find(y);
  if (x != y) {
    if (sz[x] < sz[y])
      swap(x, y);
    pa[y] = x;
    sz[x] += sz[y];
  }
}
inline void init(ll n) {
  fill(sz, sz + n, 1);
  iota(pa, pa + n, 0);
}
