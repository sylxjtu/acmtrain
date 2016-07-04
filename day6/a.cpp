#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int seq[1010];
int f[1010];

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &seq[i]);
  }
  int ret = 1;
  f[0] = 1;
  for(int i = 1; i < n; i++){
    f[i] = 1;
    for(int j = 0; j < i; j++){
      if(seq[j] < seq[i]) f[i] = max(f[i], f[j]+1);
    }
    ret = max(ret, f[i]);
  }
  printf("%d\n", ret);
  return 0;
}
