#include "../t_head.h"
const ll PN = 31622 + 5; // sqrt(1e9 + 5)
bitset<PN> is_prime;
ll p[PN], pcnt = 0;

void init() {
  is_prime.set(), is_prime[0] = is_prime[1] = false;
  for (ll i = 2; i * i < PN; ++i)
    for (ll j = i * i; is_prime[i] && j < PN; j += i)
      is_prime[j] = false;
  for (ll i = 2; i < PN; ++i)
    if (is_prime[i])
      p[pcnt++] = i;
}

ll divisor_count(ll x) {
  ll cnt, res = 1;
  REP(i, pcnt)
  if (p[i] * p[i] <= x) {
    cnt = 1;
    while (x % p[i] == 0)
      x /= p[i], cnt++;
    res *= cnt;
  } else
    break;
  return res * (x > 1 ? 2 : 1);
}
