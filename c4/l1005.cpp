#include <bits/stdc++.h>
using namespace std;

long long a[1010];
int b[1010];
int p[1010];

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    int x;
    cin >> x;
    p[x] = i;
    cin >> b[i];
  }
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    cout << a[p[x]] << " " << b[p[x]] << endl;
  }
  return 0;
}
