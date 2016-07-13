#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

char a[10010], b[10010];

int main(){
  scanf(" %[^\n] %[^\n]", a, b);
  for(int i = 0; a[i]; i++){
    for(int j = 0; b[j]; j++){
      if(a[i] == b[j]) goto cont;
    }
    cout << a[i];
    cont:;
  }
  printf("\n");
  return 0;
}
