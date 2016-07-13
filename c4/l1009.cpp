#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int x;

  cin >> x;
  int cura = 0, curb = 1;

  for (int i = 0; i < x; i++) {
    int a, b;
    scanf("%d/%d", &a, &b);

    if (b < 0) {
      a = -a; b = -b;
    }
    int g = gcd(curb, b);
    a    *= curb / g;
    cura *= b / g;
    cura += a;
    curb  = curb / g * b;
  }
  int g = gcd(cura, curb);
  cura /= g; curb /= g;

  int z = cura / curb;
  cura %= curb;

  if (z) printf("%d", z);

  if (z && cura) printf(" ");

  if (cura) printf("%d/%d\n", cura, curb);

  if (!z && !cura) printf("0\n");
  return 0;
}
