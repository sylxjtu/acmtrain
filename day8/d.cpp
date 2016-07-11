#include <cstdio>
using namespace std;

int next[1000010];
char str[1000010];
int len;

int kmp(){
  next[0] = 0;
  int i, j;
  for(i = 1, j = 0; str[i]; i++){
    while(j > 0 && str[i] != str[j]) j = next[j];
    if(str[i] == str[j]) j++;
    next[i] = j;
  }
  return i;
}

int main(){
  while (1) {
    scanf("%s", str);
    if(str[0] == '.' && str[1] == 0){
      return 0;
    }
    else{
      len = kmp();
      for(int i = 0; i < len; i++){
        printf("next[%d] = %d\n", i, next[i]);
      }
      int cnt = 0, i = len-1;
      while((i = next[i]) != 0) cnt++;
      printf("%d\n", cnt);
    }
  }
}
