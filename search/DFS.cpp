#include "../t_head.h"

bool dfs(auto &g, auto &vis, ll u, ll s) {
  if (u == s)
    return true;
  vis[u] = true;
  for (auto v : g[u]) {
    if (vis[v])
      continue;
    if (dfs(g, vis, v))
      return true;
  }
  return false;
}

bool dfs_sk(auto &g, auto &vis, ll u, ll s) {
  stack<ll> sk;
  vis[u] = true;
  sk.push(u);
  while (sk.size()) {
    auto u = sk.top();
    sk.pop();
    if (u == s)
      return true;
    for (auto v : g[u]) {
      if (vis[v])
        continue;
      vis[v] = true;
      sk.push(v);
    }
  }
  return false;
}
