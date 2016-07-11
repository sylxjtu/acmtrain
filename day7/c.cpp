#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

struct cow{
  int low;
  int high;
  bool operator< (const cow& c2) const{
    return high > c2.high;
  }
};

struct lotion{
  int spf;
  int cover;
  bool operator< (const lotion& l2) const{
    return spf < l2.spf;
  }
};

bool cmp (const cow& c1, const cow& c2){
  return c1.low < c2.low;
}

cow cowv[2510];
lotion lotionv[2510];
priority_queue<cow> cowq;

int main(){
  int c, l, cnt = 0;
  scanf("%d%d", &c, &l);
  for(int i = 0; i < c; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    cowv[i].low = x; cowv[i].high = y;
  }
  for(int i = 0; i < l; i++){
    int x, y;
    scanf("%d%d", &x, &y);
    lotionv[i].spf = x; lotionv[i].cover = y;
  }
  sort(cowv, cowv + c, cmp);
  sort(lotionv, lotionv + l);
  int curp = 0;
  for(int i = 0; i < l; i++){
    while(lotionv[i].cover-- > 0){
      //printf("%d %d\n", lotionv[i].spf, lotionv[i].cover);
      for(; curp < c; curp++){
        if(cowv[curp].low <= lotionv[i].spf){
          cowq.push(cowv[curp]);
          //printf("push %d\n", curp);
        }
        else{
          break;
        }
      }
      while(!cowq.empty() && cowq.top().high < lotionv[i].spf){
        //printf("pop %d\n", cowq.top().high);
        cowq.pop();
      }
      if(!cowq.empty()){
        cnt++;
        cowq.pop();
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
