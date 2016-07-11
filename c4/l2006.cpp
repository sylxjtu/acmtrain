#include <bits/stdc++.h>
using namespace std;

int n;

int bak[40];
int mid[40];

int val[40];
int leftNode[40];
int rightNode[40];
int treep;

int rebuildTree(int ml, int mr, int bl, int br){
  //printf("%d %d %d %d\n", ml, mr, bl, br);
  if(mr - ml == 0) return 0;
  if(mr - ml == 1){
    val[treep++] = mid[ml];
    return treep - 1;
  }
  int ret = treep;
  val[treep++] = bak[br-1];
  for(int i = 0; i < n; i++){
    if(bak[br-1] == mid[i]){
      leftNode[ret] = rebuildTree(ml, i, bl, bl + i - ml);
      rightNode[ret] = rebuildTree(i+1, mr, br + i - mr, br - 1);
      break;
    }
  }
  return ret;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; i++){
    cin >> bak[i];
  }
  for(int i = 0; i < n; i++){
    cin >> mid[i];
  }
  int head = rebuildTree(0, n, 0, n);
  queue<int> bfs;
  bfs.push(head);
  while(!bfs.empty()){
    if(bfs.front() != head) cout << " ";
    cout << val[bfs.front()];
    if(leftNode[bfs.front()]) bfs.push(leftNode[bfs.front()]);
    if(rightNode[bfs.front()]) bfs.push(rightNode[bfs.front()]);
    bfs.pop();
  }
  cout << "\n";
  return 0;
}
