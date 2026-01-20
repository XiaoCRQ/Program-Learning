#include "t_head.h"
// 高精度

string strip(string s) {
  int i = 0, n = s.size();
  while (i + 1 < n && s[i] == '0')
    i++;
  s = s.substr(i);
  if (s == "-0")
    s = "0";
  return s;
}

bool neg(const string &s) { return s[0] == '-'; }

string abs_s(string s) {
  if (s[0] == '-')
    s.erase(s.begin());
  return s;
}

// 比较 |a| 和 |b|
int cmp_abs(string a, string b) {
  a = strip(abs_s(a));
  b = strip(abs_s(b));
  if (a.size() != b.size())
    return a.size() < b.size() ? -1 : 1;
  if (a == b)
    return 0;
  return a < b ? -1 : 1;
}

string sub(string a, string b);
string add(string a, string b) { // a+b
  if (neg(a) && neg(b))
    return "-" + add(abs_s(a), abs_s(b));
  if (neg(a))
    return sub(b, abs_s(a));
  if (neg(b))
    return sub(a, abs_s(b));

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string c;
  int carry = 0;
  for (int i = 0; i < (int)max(a.size(), b.size()) || carry; i++) {
    int x = carry;
    if (i < (int)a.size())
      x += a[i] - '0';
    if (i < (int)b.size())
      x += b[i] - '0';
    c.push_back(char('0' + x % 10));
    carry = x / 10;
  }

  reverse(c.begin(), c.end());
  return strip(c);
}

string sub(string a, string b) { // a-b
  if (neg(b))
    return add(a, abs_s(b));
  if (neg(a))
    return "-" + add(abs_s(a), b);

  if (cmp_abs(a, b) < 0)
    return "-" + sub(b, a);

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string c;
  int borrow = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    int x = (a[i] - '0') - borrow;
    if (i < (int)b.size())
      x -= (b[i] - '0');
    if (x < 0)
      x += 10, borrow = 1;
    else
      borrow = 0;
    c.push_back(char('0' + x));
  }

  while (c.size() > 1 && c.back() == '0')
    c.pop_back();
  reverse(c.begin(), c.end());
  return strip(c);
}

string mul(string a, string b) { // a*b
  bool sgn = neg(a) ^ neg(b);
  a = abs_s(a), b = abs_s(b);

  int n = a.size(), m = b.size();
  vector<int> v(n + m);

  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--)
      v[i + j + 1] += (a[i] - '0') * (b[j] - '0');

  for (int i = n + m - 1; i > 0; i--) {
    v[i - 1] += v[i] / 10;
    v[i] %= 10;
  }

  string c;
  int i = 0;
  while (i + 1 < n + m && v[i] == 0)
    i++;
  for (; i < n + m; i++)
    c.push_back(char('0' + v[i]));

  if (c == "")
    c = "0";
  if (sgn && c != "0")
    c = "-" + c;
  return c;
}

string divi(string a, string b) { // a/b
  bool sgn = neg(a) ^ neg(b);
  a = abs_s(a);
  b = abs_s(b);

  string cur, res;
  for (char ch : a) {
    cur.push_back(ch);
    cur = strip(cur);
    int x = 0;
    while (cmp_abs(cur, b) >= 0) {
      cur = sub(cur, b);
      x++;
    }
    res.push_back(char('0' + x));
  }

  res = strip(res);
  if (sgn && res != "0")
    res = "-" + res;
  return res;
}
