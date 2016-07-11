#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> v;
  for(int i = 0; i < 3; i++){
    int x;
    cin >> x;
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++){
    if(i) cout << "->";
    cout << v[i];
  }
  cout << endl;
  return 0;
}
