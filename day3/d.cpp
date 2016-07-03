#include <bits/stdc++.h>
using namespace std;

int influ[9][9] = {
  {1, 1, 0, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0, 0, 0, 0},
  {0, 1, 1, 0, 1, 1, 0, 0, 0},
  {1, 0, 0, 1, 0, 0, 1, 0, 0},
  {0, 1, 0, 1, 1, 1, 0, 1, 0},
  {0, 0, 1, 0, 0, 1, 0, 0, 1},
  {0, 0, 0, 1, 1, 0, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 1, 1},
  {0, 0, 0, 0, 1, 1, 0, 1, 1},
};

int cloc[9];
int tmp[9], tmp2[9];
typedef pair<int,int> P;
queue<pair<int,int>> syl;
set<int> seen;

int hashme(int* v){
  int ret = 0;
  for(int i = 0; i < 9; i++){
    ret |= v[i];
    ret <<= 2;
  }
  ret >>=2;
  return ret;
}

void unhashme(int x, int* v){
  for(int i = 8; i >= 0; i--){
    v[i] = x & 3;
    x >>= 2;
  }
}

int main(){
  for(int i = 0; i < 9; i++){
    cin >> cloc[i];
    cloc[i] %= 12;
    cloc[i] /= 3;
  }
  syl.push(P(hashme(cloc),0));
  seen.insert(hashme(cloc));
  while(!syl.empty()){
    unhashme(syl.front().first, tmp);
    unhashme(syl.front().second, tmp2);
    syl.pop();
    int res = hashme(tmp);
    if(!res){
      int init = 0;
      for(int i = 0; i < 9;){
        while(!tmp2[i]){
          if(i>=9){
            cout << endl;
            return 0;
          }
          i++;
        }
        if(init != 0)
          cout << " ";
        else init = 1;
        cout << i+1;
        tmp2[i]--;
      }
      cout << endl;
      return 0;
    }
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        tmp[j]+=influ[i][j];
        tmp[j]%=4;
      }
      tmp2[i]++;
      tmp2[i] %= 4;
      res = hashme(tmp);
      if(!seen.count(res)){
        syl.push(P(res,hashme(tmp2)));
        seen.insert(res);
      }
    }
  }
  return 0;
}
