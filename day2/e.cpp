#include <bits/stdc++.h>
using namespace std;

long long a[100010];

// f(x, x+1, n, axplus) = a[x] + axplus;
// f(x, y, 1, axplus) = sum (x, y) + axplus;
// f(x, y, n, axplus) = min ( max( a[x]+axplus, f(x+1, y, n, 0) ), f(x+1, y, n, axplus+a[x]) );

struct param{
  int x;
  int y;
  int n;
  int axplus;
  param(int x, int y, int n, int axplus): x(x), y(y), n(n), axplus(axplus){}
};

bool operator< (const param& p1, const param& p2){
  if(p1.x < p2.x){
    return true;
  }
  else if(p1.x == p2.x){
    if(p1.y < p2.y){
      return true;
    }
    else if(p1.y == p2.y){
      if(p1.n < p2.n){
        return true;
      }
      else if(p1.n == p2.n){
        return p1.axplus < p2.axplus;
      }
    }
  }
  return false;
}

map<param, long long> m;

long long f(int x, int y, int n, int axplus){
  if(m.count(param(x,y,n,axplus))){
    return m[param(x,y,n,axplus)];
  }
  long long& ans = m[param(x,y,n,axplus)];
  if(y - x == 1){
    return ans = a[x]+axplus;
  }
  if(n == 1){
    ans = axplus;
    for(int i = x; i < y; i++){
      ans += a[x];
    }
    return ans;
  }
  else{
    return ans = min( max(a[x]+axplus, f(x+1, y, n-1, 0)), f(x+1, y, n, axplus+a[x]) );
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  cout << f(0, n, m, 0);
  return 0;
}
