#include "creat.cpp"
inline ll msb(ll x) { return __builtin_clzll(x); }
inline ll lg2(ll x) { return sizeof(ll) * 8 - 1 - msb(x); }
const ll LOGE = 20, N = 2e5;
vector<array<ll, LOGE>> Jump;
vector<bool> vis;
vector<ll> pa, h;
G g;

void init() {
  vis.assign(N, false);
  Jump.assign(N, {});
  h.assign(N, 0);
  pa.resize(N);
  iota(pa.begin(), pa.end(), 0);
}

void JumpBuild(ll u = 1) {
  for (ll i = 0; i < LOGE - 1; i++)
    Jump[u][i + 1] = Jump[Jump[u][i]][i];
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (!vis[g.to[i]]) {
      pa[g.to[i]] = Jump[g.to[i]][0] = u;
      h[g.to[i]] = h[u] + 1, vis[g.to[i]] = true;
      JumpBuild(g.to[i]);
    }
}

ll lca(ll u, ll v) {
  if (h[u] < h[v])
    swap(u, v);
  while (h[u] > h[v])
    u = Jump[u][lg2(h[u] - h[v])];
  for (ll x = LOGE - 1; x >= 0; x--)
    if (Jump[u][x] != Jump[v][x])
      u = Jump[u][x], v = Jump[v][x];
  return u == v ? u : pa[u];
}
