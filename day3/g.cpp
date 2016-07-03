#include <bits/stdc++.h>
using namespace std;

int n, c;
unsigned change[4] = {
  0x3f,
  0x2a,
  0x15,
  0x24,
};
int statusl[6];
unsigned tmpl = 0x3f;

set< vector<int> > rs;

void print(){
  vector<int> tv;
  for(int i = 0; i < n; i++){
    tv.push_back((tmpl>>(5-(i%6))&1));
  }
  rs.insert(tv);
}

int ok(){
  for(int i = 0; i < 6; i++){
    if((statusl[i] == 1 && ((tmpl>>(5-i))&1) == 0) || (statusl[i] == 2 && ((tmpl>>(5-i))&1) == 1)) return 0;
  }
  return 1;
}

void solve(){
  if(c == 0){
    if(ok()) print();
  }
  else if(c == 1){
    for(int i = 0; i < 4; i++){
      tmpl ^= change[i];
      if(ok()) print();
      tmpl ^= change[i];
    }
  }
  else if(c == 2){
    if(ok()) print();
    for(int i = 0; i < 4; i++){
      for(int j = i+1; j < 4; j++){
        tmpl ^= change[i];
        tmpl ^= change[j];
        if(ok()) print();
        tmpl ^= change[i];
        tmpl ^= change[j];
      }
    }
  }
  else if(c & 1){
    for(int i = 0; i < 4; i++){
      tmpl ^= change[i];
      if(ok()) print();
      tmpl ^= change[i];
    }
    for(int i = 0; i < 4; i++){
      for(int j = i+1; j < 4; j++){
        for(int k = j+1; k < 4; k++){
          tmpl ^= change[i];
          tmpl ^= change[j];
          tmpl ^= change[k];
          if(ok()) print();
          tmpl ^= change[i];
          tmpl ^= change[j];
          tmpl ^= change[k];
        }
      }
    }
  }
  else{
    if(ok()) print();
    for(int i = 0; i < 4; i++){
      for(int j = i+1; j < 4; j++){
        tmpl ^= change[i];
        tmpl ^= change[j];
        if(ok()) print();
        tmpl ^= change[i];
        tmpl ^= change[j];
      }
    }
    tmpl ^= change[0];
    tmpl ^= change[1];
    tmpl ^= change[2];
    tmpl ^= change[3];
    if(ok()) print();
    tmpl ^= change[0];
    tmpl ^= change[1];
    tmpl ^= change[2];
    tmpl ^= change[3];
  }
}

int main(){
  cin >> n >> c;
  while (1) {
    int x;
    cin >> x;
    if(x != -1){
      if(statusl[(x-1)%6] == 2){
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
      statusl[(x-1)%6] = 1;
    }
    else break;
  }
  while (1) {
    int x;
    cin >> x;
    if(x != -1){
      if(statusl[(x-1)%6] == 1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
      }
      statusl[(x-1)%6] = 2;
    }
    else break;
  }
  solve();
  for(auto &i: rs){
    for(int j = 0; j < i.size(); j++){
      cout << i[j];
    }
    cout << endl;
  }
  if(rs.empty()){
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
