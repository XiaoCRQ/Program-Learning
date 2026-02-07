#include "creat.cpp"
ll query_head[NODE], query_list[EDGE];
ll query_to[EDGE], query_nxt[EDGE];
ll query_pa[NODE], query_lca[EDGE];
ll query_idx;
inline void query_add(ll u, ll v) {
  query_to[query_idx] = v, query_nxt[query_idx] = query_head[u];
  query_list[query_idx] = u, query_head[u] = query_idx++;
}
void query_init(ll q, ll n = NODE - 1) {
  memset(query_head, -1, sizeof query_head);
  iota(query_pa, query_pa + n, 0);
  query_idx = 0;
  ll u, v;
  while (q--) {
    cin >> u >> v;
    query_add(u, v);
    query_add(v, u);
  }
}
ll find(ll x) { return query_pa[x] == x ? x : query_pa[x] = find(query_pa[x]); }
void tarjan(ll u = root) { // 默认 vis[root] = true
  REPG(u)
  if (!vis[to[i]]) {
    vis[to[i]] = true, tarjan(to[i]);
    query_pa[to[i]] = u;
  }
  REPGG(u, query_head, query_nxt)
  if (vis[to[i]])
    query_lca[i ^ 1] = query_lca[i] = find(to[i]);
}
void tarjan_out(ll q) { REP(i, q) cout << query_lca << '\n'; }
