#include <bits/stdc++.h>
using namespace std;

int enemy[110][110];
int parent[110];
int n, m, k;

int findparent(int x){
  if(parent[x] != x){
    return parent[x] = findparent(parent[x]);
  }
  else{
    return x;
  }
}

int main(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) parent[i] = i;
  for(int i = 0; i < m; i++){
    int x, y, z;
    cin >> x >> y >> z;
    if(z == 1){
      parent[findparent(x)] = findparent(y);
    }
    else{
      enemy[x][y] = enemy[y][x] = 1;
    }
  }
  for(int i = 0; i < k; i++){
    int x, y;
    cin >> x >> y;
    if(findparent(x) == findparent(y)){
      if(enemy[x][y]){
        cout << "OK but...\n";
      }
      else{
        cout << "No problem\n";
      }
    }
    else{
      if(enemy[x][y]){
        cout << "No way\n";
      }
      else{
        cout << "OK\n";
      }
    }
  }
  return 0;
}
