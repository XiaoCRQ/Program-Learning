#include "../t_head.h"

template <class Op = less<>> void mq(const vl &a, const ll size, Op op = Op()) {
  ll n = a.size();
  deque<ll> que;
  FOR(i, 0, n, 1) {
    while (!que.empty() && op(a[i], a[que.back()]))
      que.pop_back();
    que.push_back(i);
    while (!que.empty() && que.front() <= i - size)
      que.pop_front();
  }
}
