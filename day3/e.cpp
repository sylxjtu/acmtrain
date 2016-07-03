#include <bits/stdc++.h>
using namespace std;

int invalid[3][200];
vector<int> solution;
int n;
int cnt = 0;

void solve(int x){
  if(x == n+1 && cnt++ < 3){
    for(int i = 0; i < n; i++){
      if(i) cout << " ";
      cout << solution[i];
    }
    cout << endl;
  }
  for(int i = 1; i <= n; i++){
    if(invalid[0][i] || invalid[1][x-i+100] || invalid[2][x+i+100]) continue;
    invalid[0][i] = invalid[1][x-i+100] = invalid[2][x+i+100] = 1;
    solution.push_back(i);
    solve(x+1);
    solution.pop_back();
    invalid[0][i] = invalid[1][x-i+100] = invalid[2][x+i+100] = 0;
  }
}

int main(){
  cin >> n;
  solve(1);
  cout << cnt << endl;
  return 0;
}
