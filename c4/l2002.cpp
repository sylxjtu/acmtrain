#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int nextNode[100000];
int val[100000];
int out[100000];
int in[100000];
int inhead = -1;
int intail = -1;
int outhead = -1;
int outtail = -1;
int visited[100000];

int main(){
  int cur, n;
  scanf("%d%d", &cur, &n);
  for(int i = 0; i < n; i++){
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    nextNode[x] = z;
    val[x] = y;
  }
  while(cur != -1){
    if(visited[val[cur]>0 ? val[cur] : -val[cur]]){
      if(outhead == -1){
        outtail = cur;
        outhead = cur;
        out[outtail] = -1;
      }
      else{
        out[outtail] = cur;
        outtail = cur;
        out[outtail] = -1;
      }
    }
    else{
      visited[val[cur]>0 ? val[cur] : -val[cur]] = 1;
      if(inhead == -1){
        intail = cur;
        inhead = cur;
        in[intail] = -1;
      }
      else{
        in[intail] = cur;
        intail = cur;
        in[intail] = -1;
      }
    }
    cur = nextNode[cur];
  }
  cur = inhead;
  while(cur != -1 && in[cur] != -1){
    printf("%05d %d %05d\n", cur, val[cur], in[cur]);
    cur = in[cur];
  }
  if(cur != -1)
    printf("%05d %d %d\n", cur, val[cur], in[cur]);
  cur = outhead;
  while(cur != -1 && out[cur] != -1){
    printf("%05d %d %05d\n", cur, val[cur], out[cur]);
    cur = out[cur];
  }
  if(cur != -1)
    printf("%05d %d %d\n", cur, val[cur], out[cur]);
  return 0;
}
