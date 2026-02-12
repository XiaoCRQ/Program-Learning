#include <bits/stdc++.h>
#define REP(i, n) for (ll i = 0, _ = (n); i < _; i++)
#define REPD(i, n) for (ll i = (ll)(n) - 1, _ = 0; i >= _; i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ull P[] = {172933, 351061, 85229, 42043}; // 冲突次数降序排序 | gcc 15.2.1
// 卡unordered_map
void solve() {
  ll n = 2e5;
  cout << n << "\n";
  REP(i, n)
  cout << i * P[0] << ' ';
  cout << "\n";
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  int T = 1; // 多组 hack
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
