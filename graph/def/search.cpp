#include "creat.cpp"
void bfs(ll u) {
  vis.reset();
  queue<ll> que;
  que.push(u);
  vis[u] = true;
  while (!que.empty()) {
    u = que.front(), que.pop();
    REPG(u)
    if (!vis[to[i]]) {
      pa[to[i]] = u, h[to[i]] = h[u] + 1;
      vis[to[i]] = true, que.push(to[i]);
    }
  }
}

void dfs(ll u) {
  REPG(u)
  if (!vis[to[i]]) {
    pa[to[i]] = u, h[to[i]] = h[u] + 1;
    vis[to[i]] = true, dfs(to[i]);
  }
}

void dfs_st(ll u) {
  vis.reset();
  stack<ll> st;
  st.push(u);
  vis[u] = true;
  while (!st.empty()) {
    u = st.top(), st.pop();
    REPG(u)
    if (!vis[to[i]]) {
      pa[to[i]] = u, h[to[i]] = h[u] + 1;
      vis[to[i]] = true, st.push(to[i]);
    }
  }
}

// vl dfs_path(ll u) {
//   vis.reset();
//   vl path[2] = {{u}, {head[u]}};
//   bool flag = true;
//   while (!path[0].empty()) {
//     flag = true;
//     ll i = path->size() - 1;
//     vis[path[0][i]] = true;
//     while (path[1][i] != -1) {
//       if (vis[to[path[1][i]]] == false) {
//         path[0].push_back(to[path[1][i]]);
//         path[1].push_back(head[to[path[1][i]]]);
//         // path[1][i] = nxt[path[1][i]];
//         // 特殊情况不可省
//         flag = false;
//         break;
//       }
//       path[1][i] = nxt[path[1][i]];
//     }
//     if (flag)
//       path[0].pop_back(), path[1].pop_back();
//   }
//   return path[0];
// }
