#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll MAX = LLONG_MAX;
const ll MIN = LLONG_MIN;
const ll INF = 1e9;
const ll LINF = 1e18;
const double PI = acos(-1.0);
const ll MAXN = 1e6 + 5;
const ll dx4[4] = {1, -1, 0, 0};
const ll dy4[4] = {0, 0, 1, -1};
const ll dx8[8] = {1, 1, 1, 0, 0, -1, -1, -1};
const ll dy8[8] = {1, 0, -1, 1, -1, 1, 0, -1};
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
  size_t operator()(const pair<ll, ll> &p) const {
    return sm64(p.first + seed) ^ (sm64(p.second + seed) >> 1);
  }
  size_t operator()(const string &s) const {
    ull h = seed;
    for (unsigned char c : s)
      h = sm64(h ^ c);
    return h;
  }
  size_t operator()(const vector<ll> &v) const {
    ull h = seed ^ v.size();
    for (ull x : v)
      h ^= sm64(x + 0x9e3779b97f4a7c15 + (h << 6) + (h >> 2));
    return h;
  }
};
ull chash::seed = chrono::steady_clock::now().time_since_epoch().count();
