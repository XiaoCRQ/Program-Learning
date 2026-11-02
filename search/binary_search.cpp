#include "../t_head.h"

ll binary_search(ll left, ll right, auto check) {
  ll res = -1;
  while (left <= right) {
    ll mid = left + ((left - right) >> 1);
    if (check(mid)) // 找到最大 check 数
      res = mid, left = mid + 1;
    else
      right = mid - 1;
  }
  return res;
}
