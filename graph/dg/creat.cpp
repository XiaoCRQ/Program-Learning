#include "../../t_head.h"
struct G {
  vector<ll> head, to, nxt;
  ll idx;
  void init(ll n) { head.assign(n, -1), idx = 0; }
  void add(ll u, ll v) {
    nxt.push_back(head[u]);
    to.push_back(v);
    head[u] = idx++;
  }
};
