#include "../../t_head.h"
struct tree_arr {
  vector<ll> t[2];
  ll n;

  inline ll lowbit(ll x) { return x & (-x); }

  tree_arr(vector<ll> &val) {
    n = val.size();
    t[0].assign(n + 2, 0), t[1].assign(n + 2, 0);
    for (ll i = 1; i <= n; i++) {
      ll x = val[i - 1];
      t[0][i] += x, t[1][i] += x * i;
      if (i + 1 <= n)
        t[0][i + 1] -= x, t[1][i + 1] -= x * (i + 1);
    }
    for (ll i = 1; i <= n; i++) {
      ll j = i + lowbit(i);
      if (j <= n)
        t[0][j] += t[0][i], t[1][j] += t[1][i];
    }
  }

  void add(ll k, ll v) {
    ll v1 = k * v;
    while (k <= n)
      t[0][k] += v, t[1][k] += v1, k += lowbit(k);
  }
  void add(ll l, ll r, ll v) { add(l, v), add(r + 1, -v); }

  ll getsum(vector<ll> &T, ll k) {
    ll ret = 0;
    while (k)
      ret += T[k], k -= lowbit(k);
    return ret;
  }

  ll prefix(ll x) { return x * getsum(t[0], x - 1) - getsum(t[1], x - 1); }
  ll get(ll l, ll r) { return prefix(r + 1) - prefix(l); }
};
