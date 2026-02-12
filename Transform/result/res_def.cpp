#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;
typedef vector<pl> vpl;
const ll MOD = 998244353;
void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll res = 0;
  auto get = [&](ll n) {
    ll res = n / 7 * a;
    if (res && n % 7)
      res += b + (n % 7 - 1) / 2 * b;
    return res;
  };
  res = max(res, get(n));
  res = max(res, n / 2 * b);
  res = max(res, n / 8 * (a + b) + max(n % 8 / 7 * a, n % 8 / 2 * b));
  cout << res << '\n';
}
int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  ll T = 1;
  cin >> T;
  while (T--)
    cout << "YES";
}
