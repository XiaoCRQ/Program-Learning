//
// ██╗  ██╗██╗ █████╗  ██████╗  ██████╗██████╗  ██████╗
// ╚██╗██╔╝██║██╔══██╗██╔═══██╗██╔════╝██╔══██╗██╔═══██╗
//  ╚███╔╝ ██║███████║██║   ██║██║     ██████╔╝██║   ██║
//  ██╔██╗ ██║██╔══██║██║   ██║██║     ██╔══██╗██║▄▄ ██║
// ██╔╝ ██╗██║██║  ██║╚██████╔╝╚██████╗██║  ██║╚██████╔╝
// ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝ ╚══██═╝
//
#include <bits/stdc++.h>
#include <vector>
#define MNNMNMM add(++r);
#define NMMNNNN auto add = [&](ll value) {
#define MNNNMNM auto remove = [&](ll value) {
#define MNNNNNN cin >> a[i], a[i] -= i;
#define NMNNNNN cin >> l >> r;
#define NMNMNNN cin >> n >> k >> q;
#define NNMMNMN cin.tie(nullptr);
#define NNNNMNN continue;
#define NNNNNMN cout << sum + dp[l] * (r - l) << endl;
#define MNMNNMN dp[i] = k - max_freq;
#define MNMNNMM dp_min[st.top()] = i;
#define NNNNNNM fast_io();
#define NNMNMMM for (int i = (1); i <= (n); i++) p[i] = p[i - 1] + a[i - 1];
#define NMMNMMM for (int i = 0; i < dp.size(); i++) {
#define NMMMMMM for (ll i = 0; i < n; i++)
#define MNNMNNN for (ll i = 0; k + i <= n; i++) {
#define NNNNMNM for (ll i = 19; ~i; i--) {
#define NNMNNNN for (ll i = size - 1; i >= 0; i--) {
#define NNNMMNN for (ll j = 1; j < top && w[i][j - 1].first != size; j++) {
#define NMNMNMN freq[cnt[a[value]]++]--;
#define MNNNMMN freq[cnt[a[value]]--]--;
#define NMMNNMM freq[cnt[a[value]]]++;
#define NNMMNNN if (!(cin >> T))
#define MNNNMMM if (w[l][i].first >= r)
#define NNNNMMM int main() {
#define NNMMNMM ios::sync_with_stdio(false);
#define NMMMNMN l = w[l][i].first;
#define NMNMMNN l--, r -= k - 1;
#define MNNMNMN ll T = 1;
#define NMMMMNM ll l = 0, r = -1;
#define NMNNMNM ll max_freq = 0;
#define NNMNNMM ll n = a.size();
#define NNMNMNN ll n, k, q;
#define MNNMMMN ll size = dp.size();
#define NNNNMMN ll sum = 0;
#define MNNMMMM ll top = 20;
#define MNNNNMM max_freq = max(max_freq, cnt[a[value]]);
#define NMNNMMN max_freq--;
#define MNNMMNM remove(l++);
#define NNNNNNN return 0;
#define MNNMMNN return p;
#define NMNMMNM return p[r + 1] - p[l];
#define NNNMMMM solve();
#define NNMMMNM st.pop();
#define NMNNNMN st.push(i);
#define MNNNMNN stack<ll> st;
#define NNMMMMN static inline void fast_io() {
#define NNNNNMM sum += w[l][i].second;
#define MNNNNNM template <typename T> inline T max3(T a, T b, T c) { return max(a, max(b, c)); }
#define NNMNNMN template <typename T> inline T min3(T a, T b, T c) { return min(a, min(b, c)); }
#define NNMNMNM template <typename T> inline T range_sum(const vector<T> &p, int l, int r) {
#define NMNNMNN template <typename T> vector<T> prefix_sum(const vector<T> &a) {
#define NNMMMNN typedef long long ll;
#define NMMNNNM typedef pair<int, int> pii;
#define NMNNNNM typedef pair<int, string> pis;
#define NMMNNMN typedef pair<ll, ll> pll;
#define NMNMMMM typedef unsigned long long ull;
#define NMMMMNN typedef vector<int> vi;
#define NMMNMMN typedef vector<ll> vl;
#define NMMNMNM typedef vector<pii> vpi;
#define NMMMNNN typedef vector<pis> vpis;
#define NMMMNMM typedef vector<pll> vpl;
#define NNMMMMM typedef vector<string> vs;
#define NMNNNMM unordered_map<ll, ll> cnt;
#define NMNMMMN using namespace std::chrono;
#define MNMNNNN using namespace std;
#define NMMNMNN vector<T> p(n + 1);
#define NNMNMMN vector<vpl> w(size, vpl(top, {size, size}));
#define NMMMMMN vl a(n), dp(n - k + 1);
#define MNMNNNM vl dp_min(dp.size(), dp.size());
#define MNNNNMN vl freq(n + 1, 0);
#define NMNMNNM void solve() {
#define NNNMMMN w[i][0].first = dp_min[i];
#define NNNMMNM w[i][0].second = (dp_min[i] - i) * dp[i];
#define NNNMNMM w[i][j].first = w[w[i][j - 1].first][j - 1].first;
#define NNNMNNM w[i][j].second = w[w[i][j - 1].first][j - 1].second + w[i][j - 1].second;
#define NNMNNNM while (!st.empty() && dp[i] < dp[st.top()]) {
#define NNNMNMN while (T--) {
#define NMMMNNM while (l < i)
#define NMNMNMM while (max_freq > 0 && freq[max_freq] == 0)
#define NNNMNNN while (q--) {
#define MNNMNNM while (r < k - 1 + i)
#define NMNNMMM }
#define NNMMNNM };
MNMNNNN NMNMMMN NNMMMNN NMNMMMM NMMNNNM NMNNNNM NMMNNMN NMMMMNN NMMNMMN NNMMMMM 
NMMNMNM NMMMNNN NMMMNMM NNMMMMN NNMMNMM NNMMNMN NMNNMMM NMNNMNN NNMNNMM NMMNMNN 
NNMNMMM MNNMMNN NMNNMMM NNMNMNM NMNMMNM NMNNMMM MNNNNNM NNMNNMN NMNMNNM NNMNMNN 
NMNMNNN NMMMMMN NMMMMMM MNNNNNN NMMMMNM NMNNMNM MNNNNMN NMNNNMM NMMNNNN NMNMNMN 
NMMNNMM MNNNNMM NNMMNNM MNNNMNM MNNNMMN NMMNNMM NMNMNMM NMNNMMN NNMMNNM MNNMNNN 
MNNMNNM MNNMNMM NMMMNNM MNNMMNM MNMNNMN NMNNMMM MNMNNNM MNNNMNN NMMNMMM NNMNNNM 
MNMNNMM NNMMMNM NMNNMMM NMNNNMN NMNNMMM MNNMMMN MNNMMMM NNMNMMN NNMNNNN NNNMMMN 
NNNMMNM NNNMMNN NNNMNMM NNNMNNM NMNNMMM NMNNMMM NNNMNNN NNNNMMN NMNNNNN NMNMMNN 
NNNNMNM MNNNMMM NNNNMNN NNNNNMM NMMMNMN NMNNMMM NNNNNMN NMNNMMM NMNNMMM NNNNMMM 
NNNNNNM MNNMNMN NNMMNNN NNNNNNN NNNMNMN NNNMMMM NMNNMMM NNNNNNN NMNNMMM 