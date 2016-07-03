#include <bits/stdc++.h>
using namespace std;

int havev[200000];

int n, m;

void generateSet(){
  for(long long i = 0; i <= m; i++){
    for(long long j = i; j <= m; j++){
      havev[i*i+j*j] = 1;
    }
  }
}

int main(){
  cin >> n >> m;
  int flag = 1;
  generateSet();
  int ta = m*m*2/(n-1)+1, tb = m*m*2;
  for(int i = 1; i <= ta; i++){
    for(int j = 0; j <= tb; j++){
      int t=j;
      if(j+i*(n-1) > tb) break;
      for(int k = 0; k <= n-1; k++){
        if(t > tb || !havev[t]) goto cont;
        t+=i;
      }
      printf("%d %d\n", j, i);
      flag = 0;
      cont:;
    }
  }
  if(flag){
    cout << "NONE" << endl;
  }
  return 0;
}
