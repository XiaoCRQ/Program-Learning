#include "../t_head.h"

ll mim() { // XOR 折半搜索
  ll n, m, res = LLONG_MAX;
  map<ll, ll> mp;
  cin >> n >> m;
  vector<ll> g(n);
  g[0] = 1;
  for (ll i = 1; i < n; i++)
    g[i] = g[i - 1] * 2;
  for (ll i = 1; i <= m; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u] |= 1LL << v;
    g[v] |= 1LL << u;
  }
  for (ll i = 0; i < (1 << (n / 2)); i++) {
    ll t = 0;
    ll cnt = 0;
    for (ll j = 0; j < n / 2; j++) {
      if ((i >> j) & 1) {
        t ^= g[j];
        ++cnt;
      }
    }
    if (!mp.count(t))
      mp[t] = cnt;
    else
      mp[t] = min(mp[t], cnt);
  }
  for (ll i = 0; i < (1 << (n - n / 2)); i++) {
    ll t = 0;
    ll cnt = 0;
    for (ll j = 0; j < (n - n / 2); j++) {
      if ((i >> j) & 1) {
        t ^= g[n / 2 + j];
        ++cnt;
      }
    }
    if (mp.count(((1ll << n) - 1) ^ t))
      res = min(res, cnt + mp[((1ll << n) - 1) ^ t]);
  }
  return res;
}
