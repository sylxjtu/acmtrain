#include <bits/stdc++.h>
using namespace std;

int dayofmonth[2][12] = {
  {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isRunYear(int n){
  return (n%400 == 0) || (n%4 == 0 && n%100 != 0);
}

int cnt[7];

int main(){
  int n;
  cin >> n;
  n+=1899;

  int totalday = 1;

  for(int i = 1900; i <= n; i++){
    for(int j = 0; j < 12; j++){
      cnt[(totalday+13)%7]++;
      totalday += dayofmonth[isRunYear(i)][j];
    }
    totalday%=7;
  }

  printf("%d %d %d %d %d %d %d\n", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4], cnt[5], cnt[6]);

  return 0;
}
