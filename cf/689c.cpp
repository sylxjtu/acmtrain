#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <limits.h>
using namespace std;

long long x;
const double eps = 1e-5;

int check(long long n){
  long long cnt = 0;
  for(int i = 2; n/(1ll*i*i*i) > 0; i++){
    cnt += n/(1ll*i*i*i);
    if(cnt >= x) return 1;
  }
  return 0;
}

int finalcheck(long long n){
  long long cnt = 0;
  for(int i = 2; n/(1ll*i*i*i) > 0; i++){
    cnt += n/(1ll*i*i*i);
  }
  return cnt == x;
}

int main(){
  scanf("%I64d", &x);
  long long high = LLONG_MAX, low = 0;
  while(high - low > 1){
    long long mid = (high + low) / 2;
    if(check(mid)){
      high = mid;
    }
    else{
      low = mid;
    }
  }
  printf("%I64d\n", finalcheck(high) ? high : -1);
  return 0;
}
