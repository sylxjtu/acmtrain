#include <bits/stdc++.h>
using namespace std;

int status[100010];
int checked[100010];

int main(){
  int x;
  cin >> x;
  for(int i = 0; i < x; i++){
    int y;
    cin >> y;
    if(y == 1){
      scanf("%*d");
      continue;
    }
    for(int j = 0; j < y; j++){
      int z;
      cin >> z;
      status[z] = 1;
    }
  }
  cin >> x;
  int flag = 0;
  for(int i = 0; i < x; i++){
    int z;
    cin >> z;
    if(!checked[z] && status[z] == 0){
      if(flag) cout << " "; else flag = 1;
      checked[z] = 1;
      printf("%05d", z);
    }
  }
  if(!flag) cout << "No one is handsome";
  cout << endl;
  return 0;
}
