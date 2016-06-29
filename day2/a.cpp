#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
// 4 5
// 88 200
// 89 400
// 97 300
// 91 500

int main(){
  int n, s;
  cin >> n >> s;
  int temp = INT_MAX-100;
  long long cnt = 0;
  for(int i = 0; i < n; i++){
    int p, a;
    cin >> p >> a;
    temp = p = min(p, temp+s);
    //cout << p << " " << a << endl;
    cnt += p*a;
  }
  cout << cnt << endl;
  return 0;
}
