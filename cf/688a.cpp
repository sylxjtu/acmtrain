#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, cnt = 0, maxcnt = 0;

  cin >> a >> b;

  for (int i = 0; i < b; i++) {
    int flag = 0;

    for (int j = 0; j < a; j++) {
      char c;
      scanf(" %c", &c);

      if (c == '0') flag = 1;
    }
    cnt    = flag ? cnt + 1 : 0;
    maxcnt = max(maxcnt, cnt);
  }
  cout << maxcnt << endl;
  return 0;
}
