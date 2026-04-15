#include "../t_head.h"
// inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// c++17 -> 支持 gcd(..) and lcm(..)
inline ll R(ll l, ll r) {
  static mt19937_64 rng(random_device{}());
  return uniform_int_distribution<ll>(l, r)(rng);
}
void solve() {}
inline ll max3(ll a, ll b, ll c) { return max(a, max(b, c)); }
inline ll min3(ll a, ll b, ll c) { return min(a, min(b, c)); }

inline ll qadd(ll a, ll b, ll mod = MOD) {
  a %= mod, b %= mod;
  ll r = a + b;
  return (r >= mod ? r - mod : r);
}

inline ll qmul(ll a, ll b, ll mod = MOD) {
  __int128 r = (__int128)a * b;
  return (ll)(r % mod);
}

ll qpow(ll a, ll b, ll mod = MOD) {
  ll res = 1;
  a %= mod;
  while (b) {
    if (b & 1)
      res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll cpp_rand(ll l, ll r) { return std::uniform_int_distribution<ll>(l, r)(rng); }
ll crand(ll l, ll r) { return rand() % (r - l + 1) + l; }

// 洗牌算法
vector<ll> sf(ll n) {
  vector<ll> p(n);
  iota(p.begin(), p.end(), 0);
  shuffle(p.begin(), p.end(), rng);
  return p;
}

// 三分
bool check(double m1, double m2) { return false; }
double trisect(double l, double r) {
  double ans;
  ll cnt = 0;
  while (cnt++ < 200) {
    double m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
    if (check(m1, m2))
      r = m2;
    else
      l = m1;
  }
  return ans;
}
