#include "../../t_head.h"
struct tree {
  vector<ll> pa, data, left, right;
  ll idx;
  tree() { idx = 0; }
  ll add() {
    pa.push_back(-1);
    data.push_back(0);
    left.push_back(-1);
    right.push_back(-1);
    return idx++;
  }
  ll ld(ll p) { return data[left[p]]; }
  ll rd(ll p) { return data[right[p]]; }
};
