#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define EACH(a) for (auto &it : a)
#define REP(i, n) for (ll i = 0, _ = (n); i < _; i++)
#define REPD(i, n) for (ll i = (ll)(n) - 1, _ = 0; i >= _; i--)
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
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

template <typename A, typename B = null_type>
using pb_hash = gp_hash_table<A, B, chash>;

inline ll leastMinutes(ll n) {
  return n <= 1 ? 1 : 32 - __builtin_clz(n - 1) + 1;
}

void solve() {
  ll n, t;
  cin >> n;
  while (n--) {
    cin >> t;
    cout << leastMinutes(t) << ' ';
  }
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  // ll T = 1;
  // cin >> T;
  // while (T--)
  solve();
  return 0;
}
//
// ██╗  ██╗██╗ █████╗  ██████╗  ██████╗██████╗  ██████╗
// ╚██╗██╔╝██║██╔══██╗██╔═══██╗██╔════╝██╔══██╗██╔═══██╗
//  ╚███╔╝ ██║███████║██║   ██║██║     ██████╔╝██║   ██║
//  ██╔██╗ ██║██╔══██║██║   ██║██║     ██╔══██╗██║▄▄ ██║
// ██╔╝ ██╗██║██║  ██║╚██████╔╝╚██████╗██║  ██║╚██████╔╝
// ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝ ╚══██═╝
//
