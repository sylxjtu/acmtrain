#include <bits/stdc++.h>
using namespace std;

set<int> route[600];
int cnt[600][600];
int deg[600];
vector<int> solution;

void dfs(int s){
  for(auto i: route[s]){
    if(cnt[s][i]){
      cnt[s][i]--; cnt[i][s]--;
      dfs(i);
    }
  }
  solution.push_back(s);
}

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    route[a].insert(b); route[b].insert(a); cnt[a][b]++; cnt[b][a]++; deg[b]++; deg[a]++;
  }
  for(int i = 0; i < 600; i++){
    if(deg[i] & 1){
      dfs(i);
      for(int i = solution.size()-1; i >= 0; i--){
        cout << solution[i] << endl;
      }
      return 0;
    }
  }
  for(int i = 0; i < 600; i++){
    if(deg[i]){
      dfs(i);
      for(int i = solution.size()-1; i >= 0; i--){
        cout << solution[i] << endl;
      }
      return 0;
    }
  }
  return 0;
}
