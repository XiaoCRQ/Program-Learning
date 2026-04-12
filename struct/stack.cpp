#include "../t_head.h"

vl ms(const vl &a) {
  ll n = a.size();
  vl res(n, n - 1);
  stack<ll> st;
  for (ll i = 0; i < n; i++) {
    while (!st.empty() && a[i] < a[st.top()])
      res[st.top()] = i, st.pop();
    st.push(i);
  }
  return res;
}
