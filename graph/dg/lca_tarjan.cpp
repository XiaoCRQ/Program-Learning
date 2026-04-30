#include "creat.cpp"
const ll N = 2e5;
vector<ll> pa, h, vis, lca;
G g, query;

void init(ll q, ll n) {
  pa.resize(n), iota(pa.begin(), pa.end(), 0);
  vis.assign(n, false), lca.resize(2 * q);
  while (q--) {
    ll u, v;
    cin >> u >> v;
    query.add(u, v);
    query.add(v, u);
  }
}
ll find(ll x) { return pa[x] = pa[x] == x ? x : find(pa[x]); }
void tarjan(ll u = 1) {
  vis[u] = true;
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (!vis[g.to[i]]) {
      tarjan(g.to[i]);
      pa[g.to[i]] = u;
    }
  for (ll i = query.head[u]; i != -1; i = query.nxt[i])
    if (vis[query.to[i]])
      lca[i ^ 1] = lca[i] = find(query.to[i]);
}
void tarjan_out(ll q) {
  for (ll i = 0; i < q; i++)
    cout << lca[i << 1] << '\n';
}
