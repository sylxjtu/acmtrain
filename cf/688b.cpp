#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
using namespace std;

char num[100010];

int main(){
  scanf("%s", num);
  int l = strlen(num);
  printf("%s", num);
  for(int i = l-1; i >= 0; i--){
    putchar(num[i]);
  }
  printf("\n");
  return 0;
}
