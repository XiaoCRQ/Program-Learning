#include "../t_head.h"
// 高精度
// + * / % = != < <= >= >
template <size_t N> class lll {
  bitset<N> bits;
  // 补码表示，bits[0] 为最低位，bits[N-1] 为符号位
  static lll from_bits(const bitset<N> &b) {
    lll r;
    r.bits = b;
    return r;
  }

public:
  lll() : bits(0) {}

  lll(long long v) {
    if (v >= 0) {
      bits = bitset<N>(static_cast<unsigned long long>(v));
    } else {
      bits = bitset<N>(static_cast<unsigned long long>(-v));
      bits.flip();
      *this = *this + lll(1);
    }
  }
  bool sign() const { return bits[N - 1]; }
  bool is_zero() const { return bits.none(); }

  lll operator-() const {
    lll r;
    r.bits = ~bits;
    return r + lll(1);
  }

  lll abs() const { return sign() ? -(*this) : *this; }
  lll operator+(const lll &o) const {
    bitset<N> res;
    bool carry = false;
    for (size_t i = 0; i < N; i++) {
      bool a = bits[i], b = o.bits[i];
      res[i] = a ^ b ^ carry;
      carry = (a & b) | (carry & (a ^ b));
    }
    return from_bits(res);
  }

  lll &operator+=(const lll &o) { return *this = *this + o; }
  lll operator-(const lll &o) const { return *this + (-o); }
  lll &operator-=(const lll &o) { return *this = *this - o; }
  lll operator*(const lll &o) const {
    bool neg = sign() ^ o.sign();
    lll a = abs(), b = o.abs(), res;
    for (size_t i = 0; i < N; i++) {
      if (b.bits[i]) {
        bitset<N> shifted;
        for (size_t j = i; j < N; j++)
          shifted[j] = a.bits[j - i];
        res = res + from_bits(shifted);
      }
    }
    return neg ? -res : res;
  }

  lll &operator*=(const lll &o) { return *this = *this * o; }
  pair<lll, lll> divmod(const lll &o) const {
    if (o.is_zero())
      throw std::domain_error("division by zero");
    bool qneg = sign() ^ o.sign();
    bool rneg = sign();
    lll a = abs(), b = o.abs();
    lll q, r;
    for (int i = (int)N - 1; i >= 0; i--) {
      bitset<N> rs;
      for (size_t j = N - 1; j > 0; j--)
        rs[j] = r.bits[j - 1];
      rs[0] = a.bits[i];
      r = from_bits(rs);

      if (!(r - b).sign()) { // r >= b
        r = r - b;
        q.bits[i] = 1;
      }
    }
    return {qneg ? -q : q, rneg ? -r : r};
  }

  lll operator/(const lll &o) const { return divmod(o).first; }
  lll operator%(const lll &o) const { return divmod(o).second; }
  lll &operator/=(const lll &o) { return *this = *this / o; }
  lll &operator%=(const lll &o) { return *this = *this % o; }
  struct Flags {
    bool S, V, Z;
  };
  Flags flags(const lll &o) const {
    bool carry = false;
    bitset<N> d;
    lll neg_o = -o;
    bool c = false;
    for (size_t i = 0; i < N; i++) {
      bool a = bits[i], b = neg_o.bits[i];
      d[i] = a ^ b ^ c;
      c = (a & b) | (c & (a ^ b));
    }
    bool S = d[N - 1];
    bool cn = c;
    bool cn_1 = false;
    {
      bool cc = false;
      for (size_t i = 0; i < N - 1; i++) {
        bool a = bits[i], b = neg_o.bits[i];
        bool s = a ^ b ^ cc;
        cc = (a & b) | (cc & (a ^ b));
        if (i == N - 2)
          cn_1 = cc;
      }
    }
    bool V = cn ^ cn_1;
    bool Z = d.none();
    return {S, V, Z};
  }

  bool operator==(const lll &o) const {
    auto f = flags(o);
    return f.Z;
  }
  bool operator!=(const lll &o) const { return !(*this == o); }
  bool operator<(const lll &o) const {
    auto f = flags(o);
    return f.S != f.V;
  }
  bool operator<=(const lll &o) const {
    auto f = flags(o);
    return (f.S != f.V) || f.Z;
  }
  bool operator>(const lll &o) const {
    auto f = flags(o);
    return (f.S == f.V) && !f.Z;
  }
  bool operator>=(const lll &o) const {
    auto f = flags(o);
    return f.S == f.V;
  }

  string to_string() const {
    if (is_zero())
      return "0";
    bool neg = sign();
    lll a = neg ? -(*this) : *this;
    lll ten(10);
    string s;
    while (!a.is_zero()) {
      auto [q, r] = a.divmod(ten);
      s += char('0' + (int)r.bits.to_ulong());
      a = q;
    }
    if (neg)
      s += '-';
    reverse(s.begin(), s.end());
    return s;
  }

  friend ostream &operator<<(ostream &os, const lll &v) {
    return os << v.to_string();
  }
};

template <size_t N> class lll_silm {
  bitset<N> bits;
  // 补码表示，bits[0] 为最低位，bits[N-1] 为符号位
  static lll_silm from_bits(const bitset<N> &b) {
    lll_silm r;
    r.bits = b;
    return r;
  }

public:
  lll_silm() : bits(0) {}
  lll_silm(long long v) {
    if (v >= 0) {
      bits = bitset<N>(static_cast<unsigned long long>(v));
    } else {
      bits = bitset<N>(static_cast<unsigned long long>(-v));
      bits.flip();
      *this = *this + lll_silm(1);
    }
  }
  bool sign() const { return bits[N - 1]; }
  bool is_zero() const { return bits.none(); }
  lll_silm operator-() const {
    lll_silm r;
    r.bits = ~bits;
    return r + lll_silm(1);
  }
  lll_silm abs() const { return sign() ? -(*this) : *this; }
  lll_silm operator+(const lll_silm &o) const {
    bitset<N> res;
    bool carry = false;
    for (size_t i = 0; i < N; i++) {
      bool a = bits[i], b = o.bits[i];
      res[i] = a ^ b ^ carry;
      carry = (a & b) | (carry & (a ^ b));
    }
    return from_bits(res);
  }
  lll_silm &operator+=(const lll_silm &o) { return *this = *this + o; }
  lll_silm operator-(const lll_silm &o) const { return *this + (-o); }
  lll_silm &operator-=(const lll_silm &o) { return *this = *this - o; }
  lll_silm operator*(const lll_silm &o) const {
    bool neg = sign() ^ o.sign();
    lll_silm a = abs(), b = o.abs(), res;
    for (size_t i = 0; i < N; i++) {
      if (b.bits[i]) {
        bitset<N> shifted;
        for (size_t j = i; j < N; j++)
          shifted[j] = a.bits[j - i];
        res = res + from_bits(shifted);
      }
    }
    return neg ? -res : res;
  }
  lll_silm &operator*=(const lll_silm &o) { return *this = *this * o; }
  pair<lll_silm, lll_silm> divmod(const lll_silm &o) const {
    if (o.is_zero())
      throw std::domain_error("division by zero");
    bool qneg = sign() ^ o.sign();
    bool rneg = sign();
    lll_silm a = abs(), b = o.abs();
    lll_silm q, r;
    for (int i = (int)N - 1; i >= 0; i--) {
      bitset<N> rs;
      for (size_t j = N - 1; j > 0; j--)
        rs[j] = r.bits[j - 1];
      rs[0] = a.bits[i];
      r = from_bits(rs);
      if (!(r - b).sign()) { // r >= b
        r = r - b;
        q.bits[i] = 1;
      }
    }
    return {qneg ? -q : q, rneg ? -r : r};
  }
  lll_silm operator/(const lll_silm &o) const { return divmod(o).first; }
  lll_silm operator%(const lll_silm &o) const { return divmod(o).second; }
  lll_silm &operator/=(const lll_silm &o) { return *this = *this / o; }
  lll_silm &operator%=(const lll_silm &o) { return *this = *this % o; }
  string to_string() const {
    if (is_zero())
      return "0";
    bool neg = sign();
    lll_silm a = neg ? -(*this) : *this;
    lll_silm ten(10);
    string s;
    while (!a.is_zero()) {
      auto [q, r] = a.divmod(ten);
      s += char('0' + (int)r.bits.to_ulong());
      a = q;
    }
    if (neg)
      s += '-';
    reverse(s.begin(), s.end());
    return s;
  }
  friend ostream &operator<<(ostream &os, const lll_silm &v) {
    return os << v.to_string();
  }
};
