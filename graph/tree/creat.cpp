#include "../../t_head.h"
struct tree {
  vector<ll> pa, data, left, right;
  ll idx;
  tree() { idx = 0; }
  ll add() {
    pa.push_back(-1);
    data.push_back(0);
    left.push_back(-1);
    right.push_back(-1);
    return idx++;
  }
  ll ld(ll p) { return data[left[p]]; }
  ll rd(ll p) { return data[right[p]]; }

  // How to use?
  // build(pre,in,0,pre.size()-1,0,in.size()-1)

  // 前序+中序建树, [l1,r1] in pre, [l2,r2] in in, 返回根节点编号
  ll build(vector<ll> &pre, vector<ll> &in, ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1)
      return -1;
    ll rt = add();
    data[rt] = pre[l1];
    if (l1 == r1)
      return rt;
    ll p = find(in.begin() + l2, in.begin() + r2 + 1, pre[l1]) - in.begin();
    ll ls = p - l2;
    left[rt] = build(pre, in, l1 + 1, l1 + ls, l2, p - 1);
    right[rt] = build(pre, in, l1 + ls + 1, r1, p + 1, r2);
    if (left[rt] != -1)
      pa[left[rt]] = rt;
    if (right[rt] != -1)
      pa[right[rt]] = rt;
    return rt;
  }

  // 后序+中序建树, [l1,r1] in post, [l2,r2] in in, 返回根节点编号
  ll build_post(vector<ll> &post, vector<ll> &in, ll l1, ll r1, ll l2, ll r2) {
    if (l1 > r1)
      return -1;
    ll rt = add();
    data[rt] = post[r1];
    if (l1 == r1)
      return rt;
    ll p = find(in.begin() + l2, in.begin() + r2 + 1, post[r1]) - in.begin();
    ll ls = p - l2;
    left[rt] = build_post(post, in, l1, l1 + ls - 1, l2, p - 1);
    right[rt] = build_post(post, in, l1 + ls, r1 - 1, p + 1, r2);
    if (left[rt] != -1)
      pa[left[rt]] = rt;
    if (right[rt] != -1)
      pa[right[rt]] = rt;
    return rt;
  }
};
