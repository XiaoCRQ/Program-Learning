#include <bits/stdc++.h>
#include <vector>
#define HOOHOHH add(++r);
#define OHHOOOO auto add = [&](ll value) {
#define HOOOHOH auto remove = [&](ll value) {
#define HOOOOOO cin >> a[i], a[i] -= i;
#define OHOOOOO cin >> l >> r;
#define OHOHOOO cin >> n >> k >> q;
#define OOHHOHO cin.tie(nullptr);
#define OOOOHOO continue;
#define OOOOOHO cout << sum + dp[l] * (r - l) << endl;
#define HOHOOHO dp[i] = k - max_freq;
#define HOHOOHH dp_min[st.top()] = i;
#define OOOOOOH fast_io();
#define OOHOHHH for (int i = (1); i <= (n); i++) p[i] = p[i - 1] + a[i - 1];
#define OHHOHHH for (int i = 0; i < dp.size(); i++) {
#define OHHHHHH for (ll i = 0; i < n; i++)
#define HOOHOOO for (ll i = 0; k + i <= n; i++) {
#define OOOOHOH for (ll i = 19; ~i; i--) {
#define OOHOOOO for (ll i = size - 1; i >= 0; i--) {
#define OOOHHOO for (ll j = 1; j < top && w[i][j - 1].first != size; j++) {
#define OHOHOHO freq[cnt[a[value]]++]--;
#define HOOOHHO freq[cnt[a[value]]--]--;
#define OHHOOHH freq[cnt[a[value]]]++;
#define OOHHOOO if (!(cin >> T))
#define HOOOHHH if (w[l][i].first >= r)
#define OOOOHHH int main() {
#define OOHHOHH ios::sync_with_stdio(false);
#define OHHHOHO l = w[l][i].first;
#define OHOHHOO l--, r -= k - 1;
#define HOOHOHO ll T = 1;
#define OHHHHOH ll l = 0, r = -1;
#define OHOOHOH ll max_freq = 0;
#define OOHOOHH ll n = a.size();
#define OOHOHOO ll n, k, q;
#define HOOHHHO ll size = dp.size();
#define OOOOHHO ll sum = 0;
#define HOOHHHH ll top = 20;
#define HOOOOHH max_freq = max(max_freq, cnt[a[value]]);
#define OHOOHHO max_freq--;
#define HOOHHOH remove(l++);
#define OOOOOOO return 0;
#define HOOHHOO return p;
#define OHOHHOH return p[r + 1] - p[l];
#define OOOHHHH solve();
#define OOHHHOH st.pop();
#define OHOOOHO st.push(i);
#define HOOOHOO stack<ll> st;
#define OOHHHHO static inline void fast_io() {
#define OOOOOHH sum += w[l][i].second;
#define HOOOOOH template <typename T> inline T max3(T a, T b, T c) { return max(a, max(b, c)); }
#define OOHOOHO template <typename T> inline T min3(T a, T b, T c) { return min(a, min(b, c)); }
#define OOHOHOH template <typename T> inline T range_sum(const vector<T> &p, int l, int r) {
#define OHOOHOO template <typename T> vector<T> prefix_sum(const vector<T> &a) {
#define OOHHHOO typedef long long ll;
#define OHHOOOH typedef pair<int, int> pii;
#define OHOOOOH typedef pair<int, string> pis;
#define OHHOOHO typedef pair<ll, ll> pll;
#define OHOHHHH typedef unsigned long long ull;
#define OHHHHOO typedef vector<int> vi;
#define OHHOHHO typedef vector<ll> vl;
#define OHHOHOH typedef vector<pii> vpi;
#define OHHHOOO typedef vector<pis> vpis;
#define OHHHOHH typedef vector<pll> vpl;
#define OOHHHHH typedef vector<string> vs;
#define OHOOOHH unordered_map<ll, ll> cnt;
#define OHOHHHO using namespace std::chrono;
#define HOHOOOO using namespace std;
#define OHHOHOO vector<T> p(n + 1);
#define OOHOHHO vector<vpl> w(size, vpl(top, {size, size}));
#define OHHHHHO vl a(n), dp(n - k + 1);
#define HOHOOOH vl dp_min(dp.size(), dp.size());
#define HOOOOHO vl freq(n + 1, 0);
#define OHOHOOH void solve() {
#define OOOHHHO w[i][0].first = dp_min[i];
#define OOOHHOH w[i][0].second = (dp_min[i] - i) * dp[i];
#define OOOHOHH w[i][j].first = w[w[i][j - 1].first][j - 1].first;
#define OOOHOOH w[i][j].second = w[w[i][j - 1].first][j - 1].second + w[i][j - 1].second;
#define OOHOOOH while (!st.empty() && dp[i] < dp[st.top()]) {
#define OOOHOHO while (T--) {
#define OHHHOOH while (l < i)
#define OHOHOHH while (max_freq > 0 && freq[max_freq] == 0)
#define OOOHOOO while (q--) {
#define HOOHOOH while (r < k - 1 + i)
#define OHOOHHH }
#define OOHHOOH };
HOHOOOO OHOHHHO OOHHHOO OHOHHHH OHHOOOH OHOOOOH OHHOOHO OHHHHOO OHHOHHO OOHHHHH 
OHHOHOH OHHHOOO OHHHOHH OOHHHHO OOHHOHH OOHHOHO OHOOHHH OHOOHOO OOHOOHH OHHOHOO 
OOHOHHH HOOHHOO OHOOHHH OOHOHOH OHOHHOH OHOOHHH HOOOOOH OOHOOHO OHOHOOH OOHOHOO 
OHOHOOO OHHHHHO OHHHHHH HOOOOOO OHHHHOH OHOOHOH HOOOOHO OHOOOHH OHHOOOO OHOHOHO 
OHHOOHH HOOOOHH OOHHOOH HOOOHOH HOOOHHO OHHOOHH OHOHOHH OHOOHHO OOHHOOH HOOHOOO 
HOOHOOH HOOHOHH OHHHOOH HOOHHOH HOHOOHO OHOOHHH HOHOOOH HOOOHOO OHHOHHH OOHOOOH 
HOHOOHH OOHHHOH OHOOHHH OHOOOHO OHOOHHH HOOHHHO HOOHHHH OOHOHHO OOHOOOO OOOHHHO 
OOOHHOH OOOHHOO OOOHOHH OOOHOOH OHOOHHH OHOOHHH OOOHOOO OOOOHHO OHOOOOO OHOHHOO 
OOOOHOH HOOOHHH OOOOHOO OOOOOHH OHHHOHO OHOOHHH OOOOOHO OHOOHHH OHOOHHH OOOOHHH 
OOOOOOH HOOHOHO OOHHOOO OOOOOOO OOOHOHO OOOHHHH OHOOHHH OOOOOOO OHOOHHH 