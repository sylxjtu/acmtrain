#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

char chs[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int cnt[7];

//highest, higher, low
int changes[10][3] = {
  {0, 0, 0},
  {0, 0, 1},
  {0, 0, 2},
  {0, 0, 3},
  {0, 1, 1},
  {0, 1, 0},
  {0, 1, 1},
  {0, 1, 2},
  {0, 1, 3},
  {1, 0, 1},
};

void roman(int x){
  int dig[] = {x/1000, x/100%10, x/10%10, x%10};
  //printf("%d %d %d %d\n", dig[0], dig[1], dig[2], dig[3]);
  cnt[6]+=dig[0];
  for(int i = 1; i < 4; i++){
    cnt[8-i*2] += changes[dig[i]][0];
    cnt[7-i*2] += changes[dig[i]][1];
    cnt[6-i*2] += changes[dig[i]][2];
  }
}

int main(){
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++){
    roman(i);
  }
  for(int i = 0; i < 7; i++){
    if (cnt[i]) {
      cout << chs[i] << " " << cnt[i] << endl;
    }
  }
  return 0;
}
