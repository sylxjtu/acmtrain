#include <cstdio>
#include <algorithm>
using namespace std;
//n 1 3402
//w 1 400
//d 1 100
//m 1 12880
//n m
//w d

int f[2][12881];
int wi[3403];
int di[3403];

int n, m;

int main(){
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d%d", &wi[i], &di[i]);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= m; j++){
      if(j >= wi[i]){
        f[i&1][j] = max(f[(i-1)&1][j], f[(i-1)&1][(j-wi[i])] + di[i]);
      }
      else{
        f[i&1][j] = f[(i-1)&1][j];
      }
    }
  }
  printf("%d\n", f[(n-1)&1][m]);
  return 0;
}
