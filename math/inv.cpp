#include "math.cpp"
const ll N = 2e5 + 5;
ll INV[N] = {0, 1};
void init_inv(int n) {
  for (int i = 2; i <= n; i++)
    INV[i] = MOD - MOD / i * INV[MOD % i] % MOD;
}
ll inv(ll a) { return qpow(a, MOD - 2); }
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
ll inv_exgcd(ll a, ll mod = MOD) {
  ll x, y;
  ll g = exgcd(a, mod, x, y);
  if (g != 1)
    return -1;
  return (x % mod + mod) % mod;
}
