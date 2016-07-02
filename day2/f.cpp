#include <bits/stdc++.h>
using namespace std;

// Sample Input
// 4
// 4 1
// 2 3
// 1 4
// 3 2
// Sample Output
// 4

int posmap[1010];
int arr[1010];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    posmap[a] = i;
    arr[i] = b;
  }
  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      if(posmap[arr[j]] < posmap[arr[i]]) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
