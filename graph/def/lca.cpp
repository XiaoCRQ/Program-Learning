#include "creat.cpp"
inline ll msb(ll x) { return __builtin_clzll(x); }
inline ll lg2(ll x) { return sizeof(ll) * 8 - 1 - msb(x); }
const ll LOGE = 20;
ll Jump[NODE][LOGE];
void JumpBuild(ll u = root) { // 默认 vis[root] = true
  ll x = h[u] ? lg2(h[u]) : 0;
  for (ll i = 0; i < x; i++)
    Jump[u][i + 1] = Jump[Jump[u][i]][i];
  REPG(u)
  if (!vis[to[i]]) {
    pa[to[i]] = Jump[to[i]][0] = u, h[to[i]] = h[u] + 1;
    vis[to[i]] = true, JumpBuild(to[i]);
  }
}

ll lca(ll u, ll v) {
  ll x, y;
  auto equal = [&](ll &a, ll &b) {
    while (h[a] > h[b])
      a = Jump[a][lg2(h[a] - h[b])];
  };
  equal(u, v), equal(v, u);
  while (pa[u] != pa[v]) {
    ll x = lg2(h[u]);
    while (Jump[u][x] == Jump[v][x])
      x--;
    u = Jump[u][x];
    v = Jump[v][x];
  }
  if (u == v)
    return u;
  return pa[u];
}
