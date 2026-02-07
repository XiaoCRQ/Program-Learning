#include "math.cpp"
const ll N = 2e5 + 5;
ll INV[N];
// 打表
void init_inv(int n) {
  INV[1] = 1;
  for (int i = 2; i <= n; i++) {
    INV[i] = MOD - MOD / i * INV[MOD % i] % MOD;
  }
}

// 费马小定理 —— 逆元
ll inv(ll a) {
  return qpow(a, MOD - 2); // MOD 必须是质数
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

// 欧几里得扩展 gcd(a,mod) == 1
ll inv_exgcd(ll a, ll mod = MOD) {
  ll x, y;
  ll g = exgcd(a, mod, x, y);
  if (g != 1)
    return -1; // 不存在逆元
  return (x % mod + mod) % mod;
}
