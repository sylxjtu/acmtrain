#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

int keyboard[4][3] ={
  {1, 2, 3},
  {4, 5, 6},
  {7, 8, 9},
  {-1, 0, -1},
};

vector< pair <int, int> > v;

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    char c; int x;
    scanf("%c", &c);
    if(c >= '0' && c <= '9'){
      x = c - '0';
      for(int j = 0; j < 4; j++){
        for(int k = 0; k < 3; k++){
          if(keyboard[j][k] == x){
            v.push_back(make_pair(j, k));
            goto brk;
          }
        }
      }
      brk:;
    }
    else i--;
  }
  for(int i = 0; i < n - 1; i++){
    v[i].first = v[i+1].first - v[i].first;
    v[i].second = v[i+1].second - v[i].second;
  }
  v.pop_back();
  int cnt = -1;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 3; j++){
      if(i != 3 || j == 1){
        int cury = i, curx = j;
        for(auto &k : v){
          cury += k.first; curx += k.second;
          if(!( cury >= 0 && cury < 4 && curx >= 0 && curx < 3 && (cury != 3 || curx == 1) ) ){
            goto no;
          }
        }
        cnt++;
        no:;
      }
    }
  }
  printf("%s\n", cnt ? "NO" : "YES" );
}
