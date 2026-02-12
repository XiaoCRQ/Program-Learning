#include <bits/stdc++.h>
using namespace std;

const string head =
    R"(//
// ██╗  ██╗██╗ █████╗  ██████╗  ██████╗██████╗  ██████╗
// ╚██╗██╔╝██║██╔══██╗██╔═══██╗██╔════╝██╔══██╗██╔═══██╗
//  ╚███╔╝ ██║███████║██║   ██║██║     ██████╔╝██║   ██║
//  ██╔██╗ ██║██╔══██║██║   ██║██║     ██╔══██╗██║▄▄ ██║
// ██╔╝ ██╗██║██║  ██║╚██████╔╝╚██████╗██║  ██║╚██████╔╝
// ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝ ╚══██═╝
//)";

const string chars[] = {"N", "M"};
const int LEN_N = 10;

/* 去除 // 注释 */
string remove_comment(string s) {
  size_t pos = s.find("//");
  if (pos != string::npos)
    s = s.substr(0, pos);
  return s;
}

/* 压缩空格（token 间保留一个空格） */
string normalize_line(const string &line) {
  stringstream ss(line);
  string tok, res;
  bool first = true;

  while (ss >> tok) {
    if (!first)
      res += ' ';
    res += tok;
    first = false;
  }
  return res;
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  vector<string> def;
  vector<string> file; // ← 改为按“行字符块”
  string line;
  cout << head << '\n';

  /* 1. 读取 + 分类 */
  while (getline(cin, line)) {
    if (line.empty())
      continue;

    if (line[0] == '#') {
      // 多行 define
      if (line.substr(0, 7) == "#define") {
        string combined = line;
        while (!combined.empty() && combined.back() == '\\') {
          combined.pop_back();
          combined += ' ';
          if (!getline(cin, line))
            break;
          combined += line;
        }
        def.push_back(combined);
      } else {
        def.push_back(line);
      }
    } else {
      // 去除 // 注释
      line = remove_comment(line);

      // 若整行被删空则跳过
      if (line.find_first_not_of(" \t\r\n") == string::npos)
        continue;

      // 压缩空格 → 形成字符块
      string normalized = normalize_line(line);

      if (!normalized.empty())
        file.push_back(normalized);
    }
  }

  /* 2. 收集“行字符块” */
  unordered_set<string> st(file.begin(), file.end());
  map<string, string> mp;
  int K = sizeof(chars) / sizeof(string);
  int N = st.size();

  /* 3. 计算定长 */
  int L = 1;
  long long cap = K;
  while (cap < N) {
    cap *= K;
    L++;
  }

  /* 4. 编码函数 */
  auto encode = [&](int x) {
    vector<string> t(L, chars[0]);
    for (int i = L - 1; i >= 0; i--) {
      t[i] = chars[x % K];
      x /= K;
    }
    string r;
    for (auto &s : t)
      r += s;
    return r;
  };

  int idx = 0;
  for (auto &s : st)
    mp[s] = encode(idx++);

  /* 5. 输出 def */
  for (auto &d : def)
    cout << d << "\n";

  /* 6. 输出映射（行块映射） */
  for (auto &[k, v] : mp)
    cout << "#define " << v << " " << k << "\n";

  /* 7. 输出 file（每行一个编码） */
  int cnt = 0;
  for (auto &line_block : file) {
    cout << mp[line_block] << " ";
    if (++cnt % LEN_N == 0)
      cout << '\n';
  }
}
