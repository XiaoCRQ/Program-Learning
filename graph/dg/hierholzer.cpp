#include "../../struct/dsu.cpp"
#include "creat.cpp"
// 欧拉道路问题
//
// 无向图中
// 设degree为奇数的点为奇点，反之为偶点
// 一个连通图中，最多只有两个奇点，遍历所有边的路线称欧拉道路
// 对于无奇点的情况下，必然存在终点与起点相同，称欧拉回路
//
// 有向图中
// 有且仅有零或两个点的入度不等于出度
// 且必须为一个点的出度恰好比入度大1（起点），一个点的入度比出度大1（终点）

vector<ll> d_in, d_out;
vector<ll> path;
dsu D;
G g;
ll m;

void hierholzer(ll s) {
  vector<ll> cur = g.head;
  vector<ll> stk = {s};
  while (!stk.empty()) {
    ll u = stk.back();
    if (cur[u] != -1) {
      ll i = cur[u];
      cur[u] = g.nxt[i];
      stk.push_back(g.to[i]);
    } else {
      path.push_back(u);
      stk.pop_back();
    }
  }
  reverse(path.begin(), path.end());
}

void init() { // 有向图欧拉道路
  ll n, s = -1;
  cin >> n >> m;
  g.init(n + 1);
  D.init(n + 1);
  d_in.assign(n + 1, 0);
  d_out.assign(n + 1, 0);
  for (ll i = 0; i < m; i++) {
    ll u, v;
    cin >> u >> v;
    g.add(u, v), D.unite(u, v);
    d_in[v]++, d_out[u]++;
  }
  // 连通性检查（忽略孤立点）
  ll d = -1;
  for (ll i = 1; i <= n; i++) {
    if (!d_in[i] && !d_out[i])
      continue;
    if (d == -1)
      d = D.find(i);
    else if (D.find(i) != d)
      return;
    s = i;
  }
  if (s == -1)
    return;
  // 出入度检查
  vector<ll> pot;
  for (ll i = 1; i <= n; i++)
    if (d_in[i] != d_out[i])
      pot.push_back(i);
  if (pot.size() != 0 && pot.size() != 2)
    return;
  if (pot.size() == 2) {
    ll x = pot[0], y = pot[1];
    ll dx = d_in[x] - d_out[x], dy = d_in[y] - d_out[y];
    if (dx > dy)
      swap(dx, dy), swap(x, y);
    if (dx != -1 || dy != 1)
      return;
    s = x;
  }
  hierholzer(s);
  for (ll v : path)
    cout << v << ' ';
  cout << '\n';
}
