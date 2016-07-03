#include <bits/stdc++.h>
using namespace std;

set<int> statusSet;
queue<int> statusQueue;
set<int> ret;
int ac, bc, cc;

inline int hashme(int a, int b, int c){
  return a<<16 | b<<8 | c;
}

inline void unhashme(int x){
  ac = x & 255;
  bc = x >> 8 & 255;
  cc = x >> 16 & 255;
}

inline void tryins(){
  if(ac == 0){
    ret.insert(cc);
  }
  if(!statusSet.count(hashme(ac, bc, cc))){
    statusSet.insert(hashme(ac, bc, cc));
    statusQueue.push(hashme(ac, bc, cc));
  }
}

inline void trya(int xl, int& x, int yl, int& y){
  int xt = x, yt = y;
  if(y < yl && x != 0){
    if(x+y <= yl){
      y += x;
      x = 0;
    }
    else{
      x -= yl - y;
      y = yl;
    }
    tryins();
    x = xt; y = yt;
  }
}

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  statusSet.insert(hashme(0, 0, c));
  statusQueue.push(hashme(0, 0, c));
  while(!statusQueue.empty()){
    unhashme(statusQueue.front());
    statusQueue.pop();
    trya(a, ac, b, bc);
    trya(b, bc, a, ac);
    trya(a, ac, c, cc);
    trya(c, cc, a, ac);
    trya(b, bc, c, cc);
    trya(c, cc, b, bc);
  }
  int f = 0;
  for(auto i: ret){
    if(f) cout << " ";
    else f++;
    cout << i;
  }
  cout << endl;
  return 0;
}
