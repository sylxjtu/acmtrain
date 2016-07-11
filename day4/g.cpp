#include <bits/stdc++.h>
using namespace std;

int holes[12][2];
int n;
int edge[2][12][12];
int pairs[6][12];
int ps[6];

int isok(){
  memset(edge[1], 0, sizeof(edge[1]));
  cout << endl;
  for(int i = 0; i < n/2; i++){
    for(int j = 0; j < 12; j++){
      if(pairs[i][j]){
        for(int k = j+1; k < 12; k++){
          if(pairs[i][k]){
            cout << j << " " << k << endl;
            edge[1][j][k] = edge[1][k][j] = 1;
            goto brk;
          }
        }
      }
    }
    brk:;
  }
  for(int i = 0; i < n; i++){
    set<int> visited;
    queue< pair<int,int> > bfs;
    visited.insert(i); bfs.push(make_pair(i, 0));
    while (!bfs.empty()) {
      int a = bfs.front().first, b = bfs.front().second;
      bfs.pop();
      for(int j = 0; j < n; j++){
        if(edge[b][a][j]){
          if(visited.count(j)){
            cout << "good" << endl;
            return 1;
          }
          else{
            visited.insert(j);
            bfs.push(make_pair(j,!b));
          }
        }
      }
    }
  }
  cout << "no good" << endl;
  return 0;
}

int combine(int p, int already){
  if(!already && isok()){
    already = 1;
  }
  if(p == n){
    return already ? isok() : 1;
  }
  int cnt = 0;
  for(int i = 0; i < n/2; i++){
    if(ps[i] != 2){
      pairs[i][p] = 1;
      ps[i]++;
      cnt+=combine(p+1, already);
      pairs[i][p] = 0;
      ps[i]--;
    }
  }
  return cnt;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> holes[i][0] >> holes[i][1];
  }
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(holes[i][1] == holes[j][1]){
        if(holes[i][0] < holes[j][0]){
          edge[0][i][j] = 1;
        }
        else{
          edge[0][j][i] = 1;
        }
      }
    }
  }
  cout << combine(0, 0)/2 << endl;
  return 0;
}
