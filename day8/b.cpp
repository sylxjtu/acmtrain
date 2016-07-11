#include <cstdio>
#include <cstring>
using namespace std;

char s[2][1000];
int n;

int commonPrefix(){
  int i = 0;
  while(s[0][i] != 0 && s[0][i] == s[1][i]) i++;
  return i;
}

int main(){
  scanf("%d", &n);
  scanf("%s", s[0]);
  int cnt = 0;
  cnt += strlen(s[0]);
  for(int i = 1; i < n; i++){
    scanf("%s", s[i%2]);
    cnt += strlen(s[i%2]) + 1 - commonPrefix();
  }
  printf("%d\n", cnt);
}
