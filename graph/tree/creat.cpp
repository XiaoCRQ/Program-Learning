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
};

// How to use?
// build_pre(t,pre,in,0,pre.size()-1,0,in.size()-1)

// 前序+中序建树, [l1,r1] in pre, [l2,r2] in in, 返回根节点编号
ll build_pre(
    tree &t, vector<ll> &pre, vector<ll> &in, ll l1, ll r1, ll l2, ll r2) {
  if (l1 > r1)
    return -1;
  ll rt = t.add();
  t.data[rt] = pre[l1];
  if (l1 == r1)
    return rt;
  ll p = find(in.begin() + l2, in.begin() + r2 + 1, pre[l1]) - in.begin();
  ll ls = p - l2;
  t.left[rt] = build_pre(t, pre, in, l1 + 1, l1 + ls, l2, p - 1);
  t.right[rt] = build_pre(t, pre, in, l1 + ls + 1, r1, p + 1, r2);
  if (t.left[rt] != -1)
    t.pa[t.left[rt]] = rt;
  if (t.right[rt] != -1)
    t.pa[t.right[rt]] = rt;
  return rt;
}

// How to use?
// build_post(t,post,in,0,post.size()-1,0,in.size()-1)

// 后序+中序建树, [l1,r1] in post, [l2,r2] in in, 返回根节点编号
ll build_post(
    tree &t, vector<ll> &post, vector<ll> &in, ll l1, ll r1, ll l2, ll r2) {
  if (l1 > r1)
    return -1;
  ll rt = t.add();
  t.data[rt] = post[r1];
  if (l1 == r1)
    return rt;
  ll p = find(in.begin() + l2, in.begin() + r2 + 1, post[r1]) - in.begin();
  ll ls = p - l2;
  t.left[rt] = build_post(t, post, in, l1, l1 + ls - 1, l2, p - 1);
  t.right[rt] = build_post(t, post, in, l1 + ls, r1 - 1, p + 1, r2);
  if (t.left[rt] != -1)
    t.pa[t.left[rt]] = rt;
  if (t.right[rt] != -1)
    t.pa[t.right[rt]] = rt;
  return rt;
}
