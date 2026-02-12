#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0, _ = (n); i < _; i++)
#define REPD(i, n) for (ll i = (ll)(n) - 1, _ = 0; i >= _; i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline ll R(ll l, ll r) {
  static mt19937_64 rng(random_device{}());
  return uniform_int_distribution<ll>(l, r)(rng);
}
void solve() {
  ll n = 2e7;
  cout << n << '\n';
  while (n--)
    cout << 2e5 << ' ';
  cout << '\n';
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  // ll T = 5;
  // cout << T << '\n';
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
