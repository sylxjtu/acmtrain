#include <bits/stdc++.h>
using namespace std;

map<int, int> pos[5];
int arr[5][20010];

bool mycmp(int a, int b){
  int cnt = 0;
  for(int i = 0; i < 5; i++){
    cnt += (pos[i][a] < pos[i][b]);
  }
  return cnt > 2;
}

int main(){
  int x;
  cin >> x;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < x; j++){
      int x;
      cin >> x;
      pos[i][x] = j;
      arr[i][j] = x;
    }
  }
  sort(arr[0], arr[0]+x, mycmp);
  for(int i = 0; i < x; i++){
    cout << arr[0][i] << endl;
  }
  return 0;
}
