#include "../t_head.h"

struct lll {
  string s;

  // ==================== 构造 ====================

  lll() : s("0") {}

  lll(string x) : s(x) { norm(s); }

  lll(const char *x) : s(x) { norm(s); }

  lll(ll x) {
    s = to_string(x);
    norm(s);
  }

private:
  // ==================== 工具函数 ====================

  static void norm(string &s) {
    while (s.size() > 1 && s[0] == '0')
      s.erase(s.begin());
  }

  static bool lesss(const string &a, const string &b) {
    if (a.size() != b.size())
      return a.size() < b.size();

    return a < b;
  }

public:
  // ==================== 输出 ====================

  friend ostream &operator<<(ostream &out, const lll &x) { return out << x.s; }

  // ==================== 比较运算 ====================
  // 无依赖

  bool operator<(const lll &o) const { return lesss(s, o.s); }

  bool operator>(const lll &o) const { return o < *this; }

  bool operator<=(const lll &o) const { return !(o < *this); }

  bool operator>=(const lll &o) const { return !(*this < o); }

  bool operator==(const lll &o) const { return s == o.s; }

  bool operator!=(const lll &o) const { return s != o.s; }

  // ==================== 加法 ====================
  // 无依赖

  lll operator+(const lll &o) const {
    string a = s, b = o.s, res;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    ll carry = 0;

    for (ll i = 0; i < max(a.size(), b.size()) || carry; i++) {
      ll x = carry;

      if (i < a.size())
        x += a[i] - '0';

      if (i < b.size())
        x += b[i] - '0';

      res += x % 10 + '0';
      carry = x / 10;
    }

    reverse(res.begin(), res.end());

    return lll(res);
  }

  // ==================== 减法 ====================
  // 依赖:
  // lesss()

  lll operator-(const lll &o) const {
    string a = s, b = o.s;

    if (lesss(a, b))
      swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string res;
    ll borrow = 0;

    for (ll i = 0; i < a.size(); i++) {
      ll x = a[i] - '0' - borrow;

      if (i < b.size())
        x -= b[i] - '0';

      if (x < 0) {
        x += 10;
        borrow = 1;
      } else {
        borrow = 0;
      }

      res += x + '0';
    }

    reverse(res.begin(), res.end());

    norm(res);

    return lll(res);
  }

  // ==================== 乘法 ====================
  // 无依赖

  lll operator*(const lll &o) const {
    vector<ll> v(s.size() + o.s.size());

    for (ll i = s.size() - 1; i >= 0; i--) {
      for (ll j = o.s.size() - 1; j >= 0; j--) {
        ll x = (s[i] - '0') * (o.s[j] - '0');

        x += v[i + j + 1];

        v[i + j + 1] = x % 10;
        v[i + j] += x / 10;
      }
    }

    string res;

    for (ll x : v) {
      if (!(res.empty() && x == 0))
        res += x + '0';
    }

    if (res.empty())
      res = "0";

    return lll(res);
  }

  // ==================== 除法 ====================
  // 依赖:
  // lesss()
  // operator-()

  lll operator/(const lll &o) const {
    string cur, res;

    for (char c : s) {
      cur += c;

      norm(cur);

      ll x = 0;

      while (!lesss(cur, o.s)) {
        cur = (lll(cur) - o).s;
        x++;
      }

      res += x + '0';
    }

    norm(res);

    return lll(res);
  }

  // ==================== 取模 ====================
  // 依赖:
  // operator/()
  // operator*()
  // operator-()

  lll operator%(const lll &o) const { return *this - (*this / o) * o; }
};
