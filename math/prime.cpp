#include "../t_head.h"

vl linear_sieve(ll n) {
  vector<bool> vis(n + 1);
  vl res;
  for (ll i = 2; i <= n; i++) {
    if (!vis[i])
      res.push_back(i);
    for (auto it : res) {
      if (i * it > n)
        break;
      vis[i * it] = true;
      if (i % it == 0)
        break;
    }
  }
  return res;
}

vl factorize(ll n, const vl primes) {
  vl res;
  for (ll p : primes) {
    if (p * p > n)
      break;
    if (n % p == 0) {
      ll cnt = 0;
      while (n % p == 0)
        n /= p, cnt++;
      res.push_back(p);
    }
  }
  if (n > 1)
    res.push_back(n);
  return res;
}
