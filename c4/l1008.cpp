#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
  int x, y, sum = 0;
  cin >> x >> y;
  for(int i = x; i <= y; i++){
    sum += i;
    printf("%5d", i);
    if((i-x) % 5 == 4) printf("\n");
  }
  if((y-x+1)%5) printf("\n");
  printf("Sum = %d\n", sum);
  return 0;
}
