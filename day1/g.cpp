#include <bits/stdc++.h>
using namespace std;

int arr[1010];
int occur[4];

int main(){
  int n, cnt = 0;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    occur[arr[i]]++;
  }
  for(int i = 0; i < occur[1]; i++){
    if(arr[i] != 1){
      if(arr[i] == 2){
        for(int j = occur[1]; j < n; j++){
          if(arr[j] == 1){
            swap(arr[i], arr[j]);
          }
        }
      }
      else{
        for(int j = n-1; j > i; j--){
          if(arr[j] == 1){
            swap(arr[i], arr[j]);
          }
        }
      }
      cnt++;
    }
  }
  for(int i = occur[1]; i < occur[1]+occur[2]; i++){
    if(arr[i] != 2){
      for(int j = n-1; j > i; j--){
        if(arr[j] == 2){
          swap(arr[i], arr[j]);
        }
      }
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
