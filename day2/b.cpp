#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
// 2 5 3
// 3 1 2
// 4 1 2
// 1 1 1

struct juice{
  int price;
  int amount;
};

bool operator< (const juice& j1, const juice& j2){
  return j1.price < j2.price;
}

juice jv[110];

int main(){
  int k, e, n;
  cin >> k >> e >> n;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    jv[i].amount = b;
    jv[i].price = c+e-a;
  }
  sort(jv, jv+n);
  long long cnt = 0;
  for(int i = 0; k > 0; i++){
    if(jv[i].amount >= k){
      cnt += k * jv[i].price;
      break;
    }
    else{
      cnt += jv[i].amount*jv[i].price;
      k -= jv[i].amount;
    }
  }
  cout << cnt << endl;
  return 0;
}
