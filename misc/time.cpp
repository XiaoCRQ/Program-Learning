#include "../t_head.h"

void time() {
  mt19937 rng(time(0)); // 随机种子

  {
    time_t now = time(0); //  现在的时间 s
    tm *t = localtime(&now);
    cout << put_time(t, "%Y-%m-%d %H:%M:%S") << '\n';
  }
  {
    tm time_now;
    string s;
    cin >> s;
    istringstream input(s);
    input >> get_time(&time_now, "%Y-%m-%d %H:%M:%S");
    time_t t = mktime(&time_now);
    ostringstream output;
    t += 1000; // s
    output << put_time(localtime(&t), "%Y-%m-%d %H:%M:%S");
  }
}

void time_chrono() {
  auto now = chrono::system_clock::now();
  auto ms = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch())
                .count();
  auto us = chrono::duration_cast<chrono::microseconds>(now.time_since_epoch())
                .count();
  auto ns = chrono::duration_cast<chrono::nanoseconds>(now.time_since_epoch())
                .count();
  cout << "ms: " << ms << "\n";
  cout << "us: " << us << "\n";
  cout << "ns: " << ns << "\n";

  {
    auto start = chrono::steady_clock::now();
    sleep(10);
    auto end = chrono::steady_clock::now();
    auto diff =
        chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cout << diff << " ms\n";
  }
  {
    auto start = chrono::high_resolution_clock::now();
    sleep(10);
    auto end = chrono::high_resolution_clock::now();
    auto diff =
        chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << diff << " us\n";
  }
}
