#include <bits/stdc++.h>
using namespace std;

const string chars[] = {"N", "M"};

/* 去除 // 注释 */
string remove_comment(string s) {
  size_t pos = s.find("//");
  if (pos != string::npos)
    s = s.substr(0, pos);
  return s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> def;
  vector<vector<string>> file;
  string line;

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

      // 空格切分
      stringstream ss(line);
      vector<string> tokens;
      string tok;
      while (ss >> tok)
        tokens.push_back(tok);

      if (!tokens.empty())
        file.push_back(tokens);
    }
  }

  /* 2. 收集 token */
  set<string> st;
  for (auto &row : file)
    for (auto &x : row)
      st.insert(x);

  unordered_map<string, string> mp;

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

  /* 6. 输出映射 */
  for (auto &[k, v] : mp)
    cout << "#define " << v << " " << k << "\n";

  /* 7. 输出 file（每行 5 个） */
  int cnt = 0;
  for (auto &row : file)
    for (auto &x : row) {
      cout << mp[x];
      cnt++;
      if (cnt == 5) {
        cout << "\n";
        cnt = 0;
      } else {
        cout << " ";
      }
    }
}
