#include <cstdio>
#include <cmath>
using namespace std;

long long in;
long long curmax = 0;
long long maxp;

int main(){
  scanf("%lld", &in);
  maxp = in;
  int sqrti = (long long)(sqrt(in)+20);
  for(int i = 2; i <= sqrti; i++){
    if(in%i == 0){
      long long tmp = in;
      in /= i;
      int j;
      for(j = i+1; j <= in; j++){
        if(in%j != 0){
          break;
        }
        in /= j;
      }
      if(j - i > curmax){
        maxp = i;
        curmax = j - i;
      }
      in = tmp;
    }
  }
  curmax = curmax ? curmax : 1;
  printf("%lld\n", curmax);
  for(int i = 0; i < curmax; i++){
    if(i) printf("*");
    printf("%lld", maxp+i);
  }
  printf("\n");
  return 0;
}
