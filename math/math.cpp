#include "../t_head.h"
// inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// c++17 -> 支持 gcd(..) and lcm(..)

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

mt19937 rng(time(0));
ll cpp_rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }
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

// 区间合并
void combine() {
  ll q;
  cin >> q;
  map<ll, ll> mp;
  while (q--) {
    ll l, r;
    cin >> l >> r;
    auto it = mp.lower_bound(l);
    if (it != mp.begin())
      --it;
    while (it != mp.end() && it->first <= r) {
      if (it->second < l) {
        ++it;
        continue;
      }
      l = min(l, it->first);
      r = max(r, it->second);
      it = mp.erase(it);
    }
    mp[l] = r;
  }
}
