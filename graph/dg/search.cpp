#include "creat.cpp"
const ll N = 2e5;
vector<bool> vis;
G g;

void bfs(ll u) {
  vis.assign(vis.size(), false);
  queue<ll> que;
  que.push(u);
  while (!que.empty()) {
    u = que.front(), que.pop();
    for (ll i = g.head[u]; i != -1; i = g.nxt[i])
      if (!vis[g.to[i]]) {
        vis[g.to[i]] = true;
        que.push(g.to[i]);
      }
  }
}

void dfs(ll u) {
  for (ll i = g.head[u]; i != -1; i = g.nxt[i])
    if (!vis[g.to[i]]) {
      vis[u] = true;
      dfs(g.to[i]);
    }
}

void dfs_st(ll u) {
  vis.assign(vis.size(), false);
  stack<ll> sk;
  while (!sk.empty()) {
    u = sk.top(), sk.pop();
    for (ll i = g.head[u]; i != -1; i = g.nxt[i])
      if (!vis[g.to[i]]) {
        vis[u] = true;
        sk.push(g.to[i]);
      }
  }
}
