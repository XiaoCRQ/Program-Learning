#include "../t_head.h"

void mq(const vector<ll> &a, const ll size) {
  ll n = a.size();
  deque<ll> que;
  for (ll i = 0; i < n; i++) {
    while (!que.empty() && a[i] > a[que.back()])
      que.pop_back();
    que.push_back(i);
    while (!que.empty() && que.front() <= i - size)
      que.pop_front();
  }
}
