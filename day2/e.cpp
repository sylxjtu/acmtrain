#include <bits/stdc++.h>
using namespace std;

int arr[100010];
int n, m;

bool solve(int x){
  int cnt = 0, l = 1;
  for(int i = 0; i < n; i++){
    cnt += arr[i];
    while(cnt > x){
      cnt = arr[i];
      l++;
      if(l > m) return false;
    }
  }
  return true;
}

int main(){
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }
  int h = INT_MAX, l = 0;
  while(h - l > 1){
    solve(l + (h - l) / 2) ? h = l + (h - l) / 2 : l = l + (h - l) / 2;
  }
  cout << h << endl;
  return 0;
}
