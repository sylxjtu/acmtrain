#include <cstdio>
#include <stack>
using namespace std;
int tmp[10000];

int main(){
  int flag = 0;
  int n;
  while(scanf("%d", &n) == 1 && n != 0){
    if(flag != 0) printf("\n"); else flag = 1;
    while(1){
      int cur = n;
      stack<int> stk;
      for(int i = 0; i < n; i++){
        scanf("%d", &tmp[i]);
        if(i == 0 && tmp[0] == 0) goto brk;
      }
      for(int i = n-1; i >= 0; i--){
        stk.push(tmp[i]);
        //printf("push %d\n", tmp[i]);
        while(!stk.empty() && stk.top() == cur){
          cur--;
          //printf("pop %d\n", stk.top());
          stk.pop();
        }
        //printf("curtop %d\n", stk.empty() ? 0 : stk.top());
      }
      printf("%s\n", stk.empty() ? "Yes" : "No");
    }
    brk:;
  }
  return 0;
}
