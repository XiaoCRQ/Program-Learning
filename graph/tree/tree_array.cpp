#include "../../t_head.h"
const ll N = 2e5 + 5;
ll t[2][N], n;

inline ll lowbit(ll x) { return x & (-x); }
void add(ll k, ll v) {
  ll v1 = k * v;
  while (k <= n)
    t[0][k] += v, t[1][k] += v1, k += lowbit(k);
}
void add(ll l, ll r, ll v) { add(l, v), add(r + 1, -v); }
ll getsum(ll *T, ll k) {
  ll ret = 0;
  while (k) {
    ret += T[k];
    k -= lowbit(k);
  }
  return ret;
}
ll prefix(ll x) { return x * getsum(t[0], x - 1) - getsum(t[1], x - 1); }
ll get(ll l, ll r) { return prefix(r + 1) - prefix(l); }
void init() { // 1-idx
  memset(t, 0, sizeof t);
  ll x;
  for (ll i = 0; i < n; i++) {
    cin >> x;
    t[0][i + 1] += x, t[1][i + 1] += x * (i + 1);
    if (i + 2 <= n)
      t[0][i + 2] -= x, t[1][i + 2] -= x * (i + 2);
  }
  for (ll i = 0; i < n; i++) {
    ll j = (i + 1) + lowbit(i + 1);
    if (j <= n)
      t[0][j] += t[0][i + 1], t[1][j] += t[1][i + 1];
  }
}
