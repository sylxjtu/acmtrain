#include <bits/stdc++.h>
using namespace std;

int table[11] = {
  1,
  2,
  4,
  8,
  16,
  32,
  64,
  128,
  256,
  512,
  1024,
};

int main(){
  int n;
  scanf("%d", &n);
  printf("2^%d = %d\n", n, table[n]);
  return 0;
}
