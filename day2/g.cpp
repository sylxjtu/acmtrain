#include <bits/stdc++.h>
using namespace std;

// Sample Input
// 6
// 0 3
// 6 7
// 3 10
// 1 5
// 2 8
// 1 9
// Sample Output
// 4

struct segment{
  int s;
  int e;
  bool operator< (const segment& s2) const{
    if(e < s2.e){
      return true;
    }
    else{
      return e == s2.e && s < s2.s;
    }
  }
};

istream& operator>> (istream& in, segment& to){
  return in >> to.s >> to.e;
}

segment vecS[200];

int main(){
  int p, c1 = 0, c2 = 0, cnt = 0;
  cin >> p;
  for(int i = 0; i < p; i++){
    cin >> vecS[i];
  }
  sort(vecS, vecS+p);
  for(int i = 0; i < p; i++){
    if(c1 <= vecS[i].s && c2 <= vecS[i].s){
      if(c1 > c2){
        //cout << vecS[i].s << " " << vecS[i].e << endl;
        cnt++;
        c1 = vecS[i].e;
        continue;
      }
      else{
        //cout << vecS[i].s << " " << vecS[i].e << endl;
        cnt++;
        c2 = vecS[i].e;
        continue;
      }
    }
    if(c1 <= vecS[i].s){
      //cout << vecS[i].s << " " << vecS[i].e << endl;
      cnt++;
      c1 = vecS[i].e;
      continue;
    }
    if(c2 <= vecS[i].s){
      //cout << vecS[i].s << " " << vecS[i].e << endl;
      cnt++;
      c2 = vecS[i].e;
      continue;
    }
    //cout << "Rejected " << "c1 = " << c1 << " c2 = " << c2 << " " << vecS[i].s << " " << vecS[i].e << endl;
  }
  cout << cnt << endl;
  return 0;
}
