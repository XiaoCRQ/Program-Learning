#include "../t_head.h"

vector<ll> ms(const vector<ll> &a) {
  ll n = a.size();
  vector<ll> res(n, n);
  stack<ll> sk;
  for (ll i = 0; i < n; i++) {
    while (!sk.empty() && a[i] < a[sk.top()])
      res[sk.top()] = i, sk.pop();
    sk.push(i);
  }
  return res;
}
