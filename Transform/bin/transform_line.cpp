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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> def, file;
  unordered_map<string, string> mp;
  string line;
  int emojis_size = sizeof(emojis) / sizeof(emojis[0]);
  int idx = 0;

  while (getline(cin, line)) {
    if (line.empty())
      continue;
    if (line[0] == '#') {
      def.push_back(line);
    } else {
      // 去掉前后空格
      size_t start = line.find_first_not_of(" \t");
      size_t end = line.find_last_not_of(" \t");
      string trimmed = line.substr(start, end - start + 1);
      file.push_back(trimmed);
      if (trimmed.size() >= 2 && trimmed[0] == '/' && trimmed[1] == '/')
        continue;
      // 生成 emoji 表示
      int n = idx;
      string emoji_str;
      do {
        emoji_str += emojis[n % emojis_size];
        n = n / emojis_size - 1; // 多个 emoji 组合
      } while (n >= 0);
      mp[trimmed] = emoji_str;
      idx++;
    }
  }

  // 输出 def
  for (auto &d : def)
    cout << d << "\n";

  // 输出 #define
  for (auto &[k, v] : mp) {
    cout << "#define " << v << " " << k << "\n";
  }

  // 输出文件内容，替换成 emoji
  for (auto &f : file) {
    if (file.size() >= 2 && f[0] == '/' && f[1] == '/')
      cout << f << '\n';
    else
      cout << mp[f] << '\n';
  }
  cout << "\n";

  return 0;
}
