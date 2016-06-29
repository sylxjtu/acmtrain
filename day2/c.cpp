#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  long long cnt = 0;
  long long maxcnt = 0;
  int mi = INT_MAX+1;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    mi = max(x, mi);
    if(cnt + x > 0) cnt += x;
    else cnt = 0;
    maxcnt = max(maxcnt,cnt);
  }
  if(maxcnt == 0){
    maxcnt = mi;
  }
  cout << maxcnt << endl;
  return 0;
}
