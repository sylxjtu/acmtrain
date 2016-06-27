#include <bits/stdc++.h>
using namespace std;

int money[11];
string name[11];
map<string, int> m;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> name[i];
    m[name[i]] = i;
  }
  string s;
  while(cin >> s){
    int mn, p;
    cin >> mn >> p;
    if(!p) continue;
    int avg = mn/p;
    for(int i = 0; i < p; i++){
      string ss;
      cin >> ss;
      money[m[s]] -= avg;
      money[m[ss]] += avg;
    }
  }
  for(int i = 0; i < n; i++){
    cout << name[i] << " " << money[i] << endl;
  }
  return 0;
}
