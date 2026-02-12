#include <bits/stdc++.h>
using namespace std;

const string emojis[] = {"AC", "AK"};
// const string emojis[] = {
//     "😀", "😃", "😄", "😁", "😆", "😅", "😂", "🤣", "🥲", "☺️",  "😊",
//     "😇", "🙂", "🙃", "😉", "😌", "😍", "🥰", "😘", "😗", "😙", "😚",
//     "😋", "😛", "😝", "😜", "🤪", "🤨", "🧐", "🤓", "😎", "🥸", "🤩",
//     "🥳", "😏", "😒", "😞", "😔", "😟", "😕", "🙁", "☹️",  "😣", "😖",
//     "😫", "😩", "🥺", "😢", "😭", "😤", "😠", "😡", "🤬", "🤯", "😳",
//     "🥵", "🥶", "😱", "😨", "😰", "😥", "😓", "🤗", "🤔", "🤭", "🤫",
//     "🤥", "😶", "😐", "😑", "😬", "🙄", "😯", "😦", "😧", "😮", "😲",
//     "🥱", "😴", "🤤", "😪", "😵", "🤐", "🥴", "🤢", "🤮", "🤧", "😷",
//     "🤒", "🤕", "🤑", "🤠", "😈", "👿", "👹", "👺", "🤡", "💩", "👻",
//     "💀", "☠️",  "👽", "👾", "🤖", "🎃", "😺", "😸", "😹", "😻", "😼"};

bool is_identifier_char(char c) { return isalnum(c) || c == '_'; }

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  vector<string> def, file;
  string line;

  // 1. 读取内容
  while (getline(cin, line)) {
    if (!line.empty() && line[0] == '#')
      def.push_back(line);
    else
      file.push_back(line);
  }

  // 2. 提取 file 中的标识符
  set<string> identifiers;
  for (auto &l : file) {
    string token;
    bool in_str = false, in_char = false;
    for (size_t i = 0; i < l.size(); i++) {
      char c = l[i];
      if (c == '"' && (i == 0 || l[i - 1] != '\\'))
        in_str ^= 1;
      if (c == '\'' && (i == 0 || l[i - 1] != '\\'))
        in_char ^= 1;
      if (!in_str && !in_char) {
        if (is_identifier_char(c))
          token += c;
        else {
          if (!token.empty()) {
            identifiers.insert(token);
            token.clear();
          }
        }
      }
    }
    if (!token.empty())
      identifiers.insert(token);
  }

  // 3. 生成 emoji 映射
  unordered_map<string, string> mp;
  int emojis_size = sizeof(emojis) / sizeof(emojis[0]);
  int idx = 0;

  // get emoji string
  auto get_emoji_str = [&](int idx) {
    string emoji_str;
    int n = idx;
    do {
      emoji_str = emojis[n % emojis_size] + emoji_str;
      n = n / emojis_size - 1; // 多个 emoji 组合
    } while (n >= 0);
    return emoji_str;
  };

  // 遍历标识符生成映射
  for (auto &id : identifiers) {
    mp[id] = get_emoji_str(idx++);
  }

  // 4. 输出 def
  for (auto &d : def)
    cout << d << "\n";

  // 5. 输出宏定义
  for (auto &[k, v] : mp) {
    cout << "#define " << v << " " << k << "\n";
  }

  // 6. 输出 file 替换标识符（保留字符串/字符常量）
  for (auto &l : file) {
    string token;
    bool in_str = false, in_char = false;
    for (size_t i = 0; i < l.size(); i++) {
      char c = l[i];
      // 进入/退出字符串或字符常量
      if (c == '"' && (i == 0 || l[i - 1] != '\\'))
        in_str ^= 1;
      if (c == '\'' && (i == 0 || l[i - 1] != '\\'))
        in_char ^= 1;

      if (!in_str && !in_char) {
        if (is_identifier_char(c))
          token += c;
        else {
          if (!token.empty()) {
            cout << mp[token];
            token.clear();
          }
          cout << c;
        }
      } else {
        // 在字符串/字符常量中，直接输出原字符
        if (!token.empty()) {
          cout << mp[token];
          token.clear();
        }
        cout << c;
      }
    }
    if (!token.empty())
      cout << mp[token];
    cout << "\n";
  }
}
