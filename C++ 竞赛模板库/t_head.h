#include <bits/stdc++.h>
#define PB push_back
#define F first
#define S second
#define RESET(a, b) memset(a, b, sizeof(a))
#define EACH(a) for (auto &it : a)
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)

using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
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
  static ull sm64(ull x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(ull x) const {
    static const ull R = chrono::steady_clock::now().time_since_epoch().count();
    return sm64(x + R);
  }

  size_t operator()(const pl &p) const {
    static const ull R = chrono::steady_clock::now().time_since_epoch().count();
    return sm64(p.F + R) ^ (sm64(p.S + R) >> 1);
  }
};
