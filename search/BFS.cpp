#include "../t_head.h"

bool bfs(auto &g, auto &vis, auto &pa, ll u, ll s) {
  queue<ll> que;
  vis[u] = true;
  que.push(u);
  while (que.size()) {
    auto u = que.front();
    que.pop();
    if (u == s)
      return true;
    for (auto v : g[u]) {
      if (vis[v])
        continue;
      vis[v] = true;
      que.push(v);
    }
  }
  return false;
}
