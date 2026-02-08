#include <bits/stdc++.h>
#define EACH(a) for (auto &it : a)
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)

using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<pl> vpl;
const ll MAX = LONG_LONG_MAX;
const ll MIN = LONG_LONG_MIN;
const int INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
const int dx4[4] = {1, -1, 0, 0};
const int dy4[4] = {0, 0, 1, -1};
const int dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const int dy8[8] = {1, 0, -1, 1, -1, 1, 0, -1};
const ll MOD = 998244353;

struct chash {
  static ull seed;
  static ull sm64(ull x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(ull x) const { return sm64(x + seed); }
  size_t operator()(ll x) const { return sm64((ull)x + seed); }
  size_t operator()(const pl &p) const {
    return sm64(p.first + seed) ^ (sm64(p.second + seed) >> 1);
  }
  size_t operator()(const string &s) const {
    ull h = seed;
    for (unsigned char c : s)
      h = sm64(h ^ c);
    return h;
  }
  size_t operator()(const vl &v) const {
    ull h = seed ^ v.size();
    for (ull x : v)
      h ^= sm64(x + 0x9e3779b97f4a7c15 + (h << 6) + (h >> 2));
    return h;
  }
};
ull chash::seed = chrono::steady_clock::now().time_since_epoch().count();

// struct chash {
//   static ull R() {
//     static ull rnd = chrono::steady_clock::now().time_since_epoch().count() ^
//                      (ull)random_device{}();
//     return rnd;
//   }
//   static ull sm64(ull x) {
//     x += 0x9e3779b97f4a7c15;
//     x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//     x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//     return x ^ (x >> 31);
//   }
//   size_t operator()(ll x) const { return sm64(x + R()); }
//   size_t operator()(ull x) const { return sm64(x + R()); }
//   size_t operator()(const pl &p) const {
//     return sm64(p.first + R()) ^ (sm64(p.second + R()) >> 1);
//   }
//
//   size_t operator()(const string &s) const {
//     ull h = R();
//     for (char c : s)
//       h = sm64(h ^ (ull)(unsigned char)c);
//     return h;
//   }
//
//   size_t operator()(const vl &v) const {
//     ull h = R();
//     for (auto &x : v)
//       h = sm64(h ^ sm64(x + R()));
//     return h;
//   }
// };
