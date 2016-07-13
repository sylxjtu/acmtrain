#include <bits/stdc++.h>
#include <cstring>
#include <cstdio>
#include <limits.h>
using namespace std;

int shortcut[200010];
int cost[200010];
set<int> visited;
queue<int> bfs;

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &shortcut[i]);
  }
  bfs.push(1);
  visited.insert(1);
  while(!bfs.empty()){
    int i = bfs.front();
    bfs.pop();
    if(i - 1 >= 1 && !visited.count(i-1)){
      cost[i-1] = cost[i]+1;
      bfs.push(i-1);
      visited.insert(i-1);
    }
    if(i + 1 <= n && !visited.count(i+1)){
      cost[i+1] = cost[i]+1;
      bfs.push(i+1);
      visited.insert(i+1);
    }
    if(!visited.count(shortcut[i])){
      cost[shortcut[i]] = cost[i]+1;
      bfs.push(shortcut[i]);
      visited.insert(shortcut[i]);
    }
  }
  for(int i = 1; i <= n; i++){
    if(i != 1) printf(" ");
    printf("%d", cost[i]);
  }
  printf("\n");
  return 0;
}
