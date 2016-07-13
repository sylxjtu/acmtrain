#include <bits/stdc++.h>
using namespace std;

int  cnt[4];
char str[] = "GPLT";

int main() {
  char c;
  int  cnta = 0;

  while (isalpha(c = getchar())) {
    c = toupper(c);

    for (int i = 0; i < 4; i++) {
      if (c == str[i]) {
        cnt[i]++; cnta++;
      }
    }
  }

  while (cnta) {
    for (int i = 0; i < 4; i++) {
      if (cnt[i]) {
        cout << str[i];
        cnt[i]--; cnta--;
      }
    }
  }
  return 0;
}
