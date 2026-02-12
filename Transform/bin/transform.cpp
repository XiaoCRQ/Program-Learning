#include <bits/stdc++.h>
using namespace std;

const string chars[] = {"N", "M"};
const int LEN_N = 10;

bool is_identifier_char(char c) { return isalnum(c) || c == '_'; }

const string head =
    R"(//
// ██╗  ██╗██╗ █████╗  ██████╗  ██████╗██████╗  ██████╗
// ╚██╗██╔╝██║██╔══██╗██╔═══██╗██╔════╝██╔══██╗██╔═══██╗
//  ╚███╔╝ ██║███████║██║   ██║██║     ██████╔╝██║   ██║
//  ██╔██╗ ██║██╔══██║██║   ██║██║     ██╔══██╗██║▄▄ ██║
// ██╔╝ ██╗██║██║  ██║╚██████╔╝╚██████╗██║  ██║╚██████╔╝
// ╚═╝  ╚═╝╚═╝╚═╝  ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝ ╚══██═╝
//)";

/* C++ 常用运算符集合（最长优先） */
const vector<string> operators = {
    ">>=", "<<=", "->*", "->", "::", "++", "--", "==", "!=", "<=",
    ">=",  "+=",  "-=",  "*=", "/=", "%=", "&&", "||", "<<", ">>",
    "+",   "-",   "*",   "/",  "%",  "=",  "<",  ">",  "!",  "&",
    "|",   "^",   "~",   "?",  ":",  ",",  ".",  ".*", "[]", "()",
};

/* 去除 // 注释 */
string remove_comment(string s) {
  size_t pos = s.find("//");
  if (pos != string::npos)
    s = s.substr(0, pos);
  return s;
}

// 尝试匹配最长运算符
bool match_operator(const string &s, size_t pos, string &op) {
  for (auto &o : operators) {
    if (s.substr(pos, o.size()) == o) {
      op = o;
      return true;
    }
  }
  return false;
}

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);
  vector<string> def, file;
  string line;
  cout << head << '\n';

  // 1. 读取内容，处理 #define 多行宏
  vector<string> raw_lines;
  while (getline(cin, line)) {
    if (line.empty())
      continue;

    if (line[0] == '#') {
      if (line.substr(0, 7) == "#define") {
        string combined = line;
        while (!combined.empty() && combined.back() == '\\') {
          combined.back() = ' '; // 将 '\' 替换为空格
          if (!getline(cin, line))
            break; // 防止 EOF
          combined += line;
        }
        def.push_back(combined);
      } else {
        def.push_back(line);
      }
    } else {
      line = remove_comment(line);
      if (line.find_first_not_of(" \t\r\n") != string::npos)
        raw_lines.push_back(line);
    }
  }

  // 2. 拆成 token
  for (auto &l : raw_lines) {
    size_t i = 0;
    while (i < l.size()) {
      if (isspace(l[i])) {
        i++;
        continue;
      }

      // 字符串和字符常量也作为 token
      if (l[i] == '"' || l[i] == '\'') {
        char quote = l[i];
        string token;
        token += l[i++];
        while (i < l.size()) {
          token += l[i];
          if (l[i] == quote && (i == 0 || l[i - 1] != '\\')) {
            i++;
            break;
          }
          i++;
        }
        file.push_back(token);
        continue;
      }

      // 尝试匹配最长运算符
      string op;
      if (match_operator(l, i, op)) {
        file.push_back(op);
        i += op.size();
        continue;
      }

      // 普通标识符/数字 token
      if (is_identifier_char(l[i])) {
        string token;
        while (i < l.size() && is_identifier_char(l[i]))
          token += l[i++];
        file.push_back(token);
        continue;
      }

      // 其他字符单独作为 token
      file.push_back(string(1, l[i++]));
    }
  }

  // 3. 提取所有 token 进入映射
  unordered_set<string> all_tokens;
  for (auto &t : file) {
    if (!t.empty())
      all_tokens.insert(t);
  }

  // 4. 生成 chars 映射
  map<string, string> mp;
  int K = sizeof(chars) / sizeof(string);
  int N = all_tokens.size();
  int L = 1;
  long long cap = K;
  while (cap < N) {
    cap *= K;
    L++;
  }

  auto get_chars_str = [&](int n) {
    vector<string> tmp(L, chars[0]);
    for (int i = L - 1; i >= 0; i--) {
      tmp[i] = chars[n % K];
      n /= K;
    }
    string res;
    for (auto &s : tmp)
      res += s;
    return res;
  };

  int idx = 0;
  for (auto &t : all_tokens)
    mp[t] = get_chars_str(idx++);

  // 5. 输出 def
  for (auto &d : def)
    cout << d << "\n";

  // 6. 输出 #define 映射
  for (auto &[k, v] : mp)
    cout << "#define " << v << " " << k << "\n";

  // 7. 输出 token，每5个换行，全部用映射
  int cnt = 0;
  for (auto &t : file) {
    if (t.empty())
      continue;
    cout << mp[t] << " ";
    if (++cnt % LEN_N == 0)
      cout << "\n";
  }
}
