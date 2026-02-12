#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0, _ = (n); i < _; i++)
#define REPD(i, n) for (ll i = (ll)(n) - 1, _ = 0; i >= _; i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
// 卡 pb_ds
void solve() {
  const ull FIX = 12345; // 固定低位
  ll n = 2e5;
  cout << n << '\n';
  REP(i, n)
  cout << ((i << 16) | FIX) << ' ';
  cout << '\n';
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  ll T = 5;
  cout << T << '\n';
  while (T--)
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
