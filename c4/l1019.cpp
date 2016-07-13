#include <bits/stdc++.h>
using namespace std;

int main(){
  int a1, a2;
  scanf("%d%d%*d", &a1, &a2);
  a1++, a2++;
  int a1o = a1, a2o = a2;
  while(1){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(b == d) continue;
    if(a + c == b) a1--;
    if(a + c == d) a2--;
    if(!a1){
      printf("A\n%d\n", a2o - a2);
      break;
    }
    if(!a2){
      printf("B\n%d\n", a1o - a1);
      break;
    }
  }
  return 0;
}
