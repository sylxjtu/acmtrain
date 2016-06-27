#include <bits/stdc++.h>
using namespace std;

// 29
// wwwbbrwrbrbrrbrbrwrwwrbwrwrrb

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;

  int cnta = 0;

  for(int i = 0; i < n; i++){
    int cnt = 0;
    int j = 0, k = 0;
    char color = 0, color2 = 0;
    for(j = i; j < n; j++){
      if(s[j] == 'w'){
        cnt++;
        continue;
      }
      if(color == 0){
        color = s[j];
        cnt++;
      }
      else{
        if(s[j] != color){
          j--;
          break;
        }
        else{
          cnt++;
        }
      }
    }
    if(j >= n-1){
      for(j = 0; j < i; j++){
        if(s[j] == 'w'){
          cnt++;
          continue;
        }
        if(color == 0){
          color = s[j];
          cnt++;
        }
        else{
          if(s[j] != color){
            j--;
            break;
          }
          else{
            cnt++;
          }
        }
      }
      for(k = i-1; k > j; k--){
        if(s[k] == 'w'){
          cnt++;
          continue;
        }
        if(color2 == 0){
          color2 = s[k];
          cnt++;
        }
        else{
          if(s[k] != color2){
            k++;
            break;
          }
          else{
            cnt++;
          }
        }
      }
    }
    else{
      for(k = i-1; k >= 0; k--){
        if(s[k] == 'w'){
          cnt++;
          continue;
        }
        if(color2 == 0){
          color2 = s[k];
          cnt++;
        }
        else{
          if(s[k] != color2){
            k++;
            break;
          }
          else{
            cnt++;
          }
        }
      }
      if(k <= 0){
        for(k = n-1; k > j; k--){
          if(s[k] == 'w'){
            cnt++;
            continue;
          }
          if(color2 == 0){
            color2 = s[k];
            cnt++;
          }
          else{
            if(s[k] != color2){
              k++;
              break;
            }
            else{
              cnt++;
            }
          }
        }
      }
    }
    cnta = max(cnta,cnt);
  }

  cout << cnta << endl;
  return 0;
}
