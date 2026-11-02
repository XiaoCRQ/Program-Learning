#include "creat.cpp"

vector<ll> pa, sz, mx, ans;
G g;

void dfs(ll u) {
  sz[u] = 1, ans[u] = u;
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (g.to[i] != pa[u]) {
      ll v = g.to[i];
      pa[v] = u;
      dfs(v);
      sz[u] += sz[v];
      mx[u] = max(mx[u], sz[v]);
    }
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    for (ll p = ans[g.to[i]]; g.to[i] != pa[u] && p != u; p = pa[p])
      if (max(mx[p], sz[u] - sz[p]) <= sz[u] / 2) {
        ans[u] = p;
        break;
      }
}

void centroid() {
  ll n = g.head.size(), q;
  ans.assign(n, 0);
  pa.assign(n, -1);
  sz.assign(n, 0);
  mx.assign(n, 0);
  dfs(1);
  while (q--) {
    ll u;
    cin >> u;
    cout << ans[u] << '\n';
  }
}
