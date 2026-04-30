#include "../t_head.h"
void comperss(vector<ll> &a) { // 去重
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
}
vector<ll> discretize(vector<ll> &a) { // 离散化
  ll n = a.size();
  vector<ll> b = a;
  comperss(b);
  for (ll i = 0; i < n; i++) {
    auto idx = lower_bound(b.begin(), b.end(), a[i]) - a.begin();
    a[i] = idx;
  }
  return b;
}
