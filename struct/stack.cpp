#include "../t_head.h"
template <typename opt> // 单调栈
vl ms(const vl &a, opt &&op = [](ll &a, ll &b) { return a < b; }) {
  ll n = a.size();
  vl res(n);
  stack<ll> st;
  REP(i, n) {
    while (!st.empty() && op(a[i], a[st.top()]))
      res[st.top()] = i, st.pop();
    st.push(i);
  }
  return res;
}
