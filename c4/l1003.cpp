#include <bits/stdc++.h>
#include <cstdio>
#include <cctype>
using namespace std;

int cnt[10];

int main(){
  char c;
  while (isdigit(c = getchar())) {
    cnt[c - '0']++;
  }
  for(int i = 0; i < 10; i++){
    if(cnt[i]) printf("%d:%d\n", i, cnt[i]);
  }
  return 0;
}
