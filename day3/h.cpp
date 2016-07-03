#include <bits/stdc++.h>
using namespace std;

char maze[500][500];
int depth[500][500];
int w, h;
typedef pair<int,int> Coor;

queue< Coor > syl;

void findin(){
  for(int i = 0; i < w; i++){
    if(maze[0][i] == ' '){
      syl.push(Coor(0, i));
      depth[0][i] = 1;
    }
    if(maze[h-1][i] == ' '){
      syl.push(Coor(h-1, i));
      depth[h-1][i] = 1;
    }
  }
  for(int i = 1; i < h-1; i++){
    if(maze[i][0] == ' '){
      syl.push(Coor(i, 0));
      depth[i][0] = 1;
    }
    if(maze[i][w-1] == ' '){
      syl.push(Coor(i, w-1));
      depth[i][w-1] = 1;
    }
  }
}

int main(){
  cin >> w >> h;
  w *= 2;
  w++;
  h *= 2;
  h++;
  for(int i = 0; i < h; i++){
    scanf("%*c%*c");
    for(int j = 0; j < w; j++){
      scanf("%c",&maze[i][j]);
    }
  }
  findin();
  Coor last = syl.front();
  while(!syl.empty()){
    last = syl.front();
    int x = last.first, y = last.second;
    syl.pop();
    for(int i = -1; i <= 1; i++){
      if(x+i < 0 || x+i >= h || maze[x+i][y] != ' ') continue;
      if(!depth[x+i][y] || depth[x+i][y] > depth[x][y]+1){
        depth[x+i][y] = depth[x][y]+1;
        syl.push(Coor(x+i, y));
      }
    }
    for(int i = -1; i <= 1; i++){
      if(y+i < 0 || y+i >= w || maze[x][y+i] != ' ') continue;
      if(!depth[x][y+i] || depth[x][y+i] > depth[x][y]+1){
        depth[x][y+i] = depth[x][y]+1;
        syl.push(Coor(x, y+i));
      }
    }
  }
  int maxmove = 0;
  //cout << endl;
  for(int i = 1; i < h; i+=2){
    for(int j = 1; j < w; j+=2){
      //printf("   %3d", depth[i][j]);
      if(depth[i][j]) maxmove = max(maxmove, depth[i][j]);
    }
    //cout << endl << endl;
  }
  cout << maxmove/2 << endl;
  return 0;
}
