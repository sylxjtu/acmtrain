#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[110];
int f[110][110];
int len;
int res;

int main(){
  while(scanf("%s", str) == 1 && str[0] != 'e'){
    len = strlen(str);
    res = 0;
    for(int l = 1; l <= len; l++){
      for(int s = 0; s <= len - l; s++){
        if(l == 1) f[s][s+l] = 0;
        else{
          f[s][s+l] = f[s][s+l-1];
          for(int e = s+l-2; e >= s; e--){
            if( (str[s+l-1] == ')' && str[e] == '(')  || (str[s+l-1] == ']' && str[e] == '[') ){
              f[s][s+l] = max(f[s][s+l], f[s][e] + f[e+1][s+l-1] + 2);
            }
          }
        }
      }
    }
    // for(int i = 0; i < len; i++){
    //   for(int j = 1; j <= len; j++){
    //     printf("%d", f[i][j]);
    //   }
    //   printf("\n");
    // }
    printf("%d\n", f[0][len]);
  }
  return 0;
}
