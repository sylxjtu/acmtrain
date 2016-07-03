#include <bits/stdc++.h>
using namespace std;

int need[30];
int v, ct;
int feed[20][30];
int tmpfed[30];
vector<int> solution;

int ida(int n, int d){
  if(ct - n < d) return 0;
  if(d == 0){
    for(int i = 0; i < v; i++){
      if(tmpfed[i] < need[i]){
        return 0;
      }
    }
    return 1;
  }
  else{
    for(int i = 0; i < v; i++){
      tmpfed[i] += feed[n][i];
    }
    if(ida(n+1, d-1)){
      solution.push_back(n);
      return 1;
    }
    else{
      for(int i = 0; i < v; i++){
        tmpfed[i] -= feed[n][i];
      }
      if(ida(n+1, d)) return 1;
      else return 0;
    }
  }
}

int main(){
  cin >> v;
  for(int i = 0; i < v; i++){
    cin >> need[i];
  }
  cin >> ct;
  for(int i = 0; i < ct; i++){
    for(int j = 0; j < v; j++){
      cin >> feed[i][j];
    }
  }
  for(int i = 1; i <= ct; i++){
    solution.clear();
    if(ida(0, i)){
      cout << i;
      for(int i = solution.size() - 1; i >= 0; i--){
        cout << " ";
        cout << solution[i] + 1;
      }
      cout << endl;
      return 0;
    }
  }
  return 0;
}
