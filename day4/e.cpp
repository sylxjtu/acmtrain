#include <bits/stdc++.h>
using namespace std;

int mat[110][110];
int n;
int cnt = 0;
vector<int> in;
set<int> connected;

void prim(){
  for(int i = 0; i < n-1; i++){
    int mi = INT_MAX, ege = -1;
    for(int k = 0; k <= i; k++){
      for(int j = 0; j < n; j++){
        if(mat[in[k]][j] < mi && !connected.count(j)){
          mi = mat[in[k]][j];
          ege = j;
        }
      }
    }
    cnt += mi;
    in.push_back(ege);
    connected.insert(ege);
  }
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> mat[i][j];
    }
  }
  in.push_back(0);
  connected.insert(0);
  prim();
  cout << cnt << endl;
  return 0;
}
