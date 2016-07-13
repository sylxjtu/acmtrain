#include <bits/stdc++.h>
using namespace std;

long long fact(int i){
  return i > 1 ? fact(i-1) * i : 1;
}

int main(){
  int x;
  scanf("%d", &x);
  long long cnt = 0;
  for(int i = 1; i <= x; i++){
    cnt += fact(i);
  }
  cout << cnt << endl;
  return 0;
}
