#include "../../t_head.h"

ll lis(vector<ll> &a) {
  vector<ll> p;
  ll n = a.size();
  sort(a.begin(), a.end());
  for (auto &x : a) {
    auto it = lower_bound(p.begin(), p.end(), x);
    if (it == p.end())
      p.push_back(x);
    else
      *it = x;
  }
  return p.size();
}
