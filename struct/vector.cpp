#include "../t_head.h"
void comperss(vl &a) { // 去重
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
vl discretize(vl &a) { // 离散化
  ll n = a.size();
  vl b = a;
  comperss(b);
  REP(i, n) {
    auto idx = lower_bound(b.begin(), b.end(), a[i]) - a.begin();
    a[i] = idx;
  }
  return b;
}
