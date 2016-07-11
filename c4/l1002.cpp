#include <cstdio>
using namespace std;

int n;
char str[10];

int main(){
  int cnt = 1, cur = 0;
  scanf("%d%s", &n, str);
  while(n >= cnt){
    n-=cnt;
    cnt+=(cur == 0) ? 5 : 4;
    cur++;
  }
  for(int i = 1; i < cur; i++){
    for(int j = 1; j < i; j++){
      printf(" ");
    }
    for(int j = 0; j < (cur-i)*2 + 1; j++){
      printf("%s", str);
    }
    printf("\n");
  }
  for(int j = 1; j < cur; j++){
    printf(" ");
  }
  printf("%s\n", str);
  for(int i = cur-1; i >= 1; i--){
    for(int j = 1; j < i; j++){
      printf(" ");
    }
    for(int j = 0; j < (cur-i)*2 + 1; j++){
      printf("%s", str);
    }
    printf("\n");
  }
  printf("%d\n", n);
}
