#include <bits/stdc++.h>
using namespace std;

int main(){
  int x; char c;
  scanf("%d %c", &x, &c);
  for(int i = 0; i < x/2 + x%2; i++){
    for(int j = 0; j < x; j++){
      printf("%c", c);
    }
    printf("\n");
  }
  return 0;
}
