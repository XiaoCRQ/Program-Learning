#include <bits/stdc++.h>
#include <vector>
using namespace std;
using namespace std::chrono;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<pis> vpis;
typedef vector<pll> vpl;
static inline void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}
template <typename T> vector<T> prefix_sum(const vector<T> &a) {
  ll n = a.size();
  vector<T> p(n + 1);
  for (int i = (1); i <= (n); i++) p[i] = p[i - 1] + a[i - 1];
  return p;
}
template <typename T> inline T range_sum(const vector<T> &p, int l, int r) {
  return p[r + 1] - p[l];
}
template <typename T> inline T max3(T a, T b, T c) { return max(a, max(b, c)); }
template <typename T> inline T min3(T a, T b, T c) { return min(a, min(b, c)); }
void solve() {
  ll n, k, q;
  cin >> n >> k >> q;
  vl a(n), dp(n - k + 1);
  for (ll i = 0; i < n; i++)
    cin >> a[i], a[i] -= i;
  ll l = 0, r = -1;
  ll max_freq = 0;
  vl freq(n + 1, 0);
  unordered_map<ll, ll> cnt;
  auto add = [&](ll value) {
    freq[cnt[a[value]]++]--;
    freq[cnt[a[value]]]++;
    max_freq = max(max_freq, cnt[a[value]]);
  };
  auto remove = [&](ll value) {
    freq[cnt[a[value]]--]--;
    freq[cnt[a[value]]]++;
    while (max_freq > 0 && freq[max_freq] == 0)
      max_freq--;
  };
  for (ll i = 0; k + i <= n; i++) {
    while (r < k - 1 + i)
      add(++r);
    while (l < i)
      remove(l++);
    dp[i] = k - max_freq;
  }
  vl dp_min(dp.size(), dp.size());
  stack<ll> st;
  for (int i = 0; i < dp.size(); i++) {
    while (!st.empty() && dp[i] < dp[st.top()]) {
      dp_min[st.top()] = i;
      st.pop();
    }
    st.push(i);
  }
  ll size = dp.size();
  ll top = 20;
  vector<vpl> w(size, vpl(top, {size, size}));
  for (ll i = size - 1; i >= 0; i--) {
    w[i][0].first = dp_min[i];
    w[i][0].second = (dp_min[i] - i) * dp[i];
    for (ll j = 1; j < top && w[i][j - 1].first != size; j++) {
      w[i][j].first = w[w[i][j - 1].first][j - 1].first;
      w[i][j].second = w[w[i][j - 1].first][j - 1].second + w[i][j - 1].second;
    }
  }
  while (q--) {
    ll sum = 0;
    cin >> l >> r;
    l--, r -= k - 1;
    for (ll i = 19; ~i; i--) {
      if (w[l][i].first >= r)
        continue;
      sum += w[l][i].second;
      l = w[l][i].first;
    }
    cout << sum + dp[l] * (r - l) << endl;
  }
}
int main() {
  fast_io();
  ll T = 1;
  if (!(cin >> T))
    return 0;
  while (T--) {
    solve();
  }
  return 0;
}
