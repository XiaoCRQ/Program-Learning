#include "../t_head.h"

template <class Op = less<>> vl ms(const vl &a, Op op = Op()) {
  ll n = a.size();
  vl res(n, n - 1);
  stack<ll> st;
  FOR(i, 0, n, 1) {
    while (!st.empty() && op(a[i], a[st.top()]))
      res[st.top()] = i, st.pop();
    st.push(i);
  }
  return res;
}
