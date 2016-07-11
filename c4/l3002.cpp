#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

char inputarr[100];

map<int, int, greater<int>> low;
int lowsize = 0;
map<int, int> high;
int highsize = 0;

int median = 0;

int stk[100000];
int stkp = 0;

void balance(){
  if(lowsize - highsize >= 2){
    high[(*low.begin()).first]++;
    low[(*low.begin()).first]--;
    if(low[(*low.begin()).first] == 0) low.erase((*low.begin()).first);
    lowsize--;
    highsize++;
  }
  else if(highsize - lowsize >= 1){
    low[(*high.begin()).first]++;
    high[(*high.begin()).first]--;
    if(high[(*high.begin()).first] == 0) high.erase((*high.begin()).first);
    lowsize++;
    highsize--;
  }
  median = (*low.begin()).first;
}

void del(int x){
  if(x > median){
    highsize--;
    high[x]--;
    if(high[x] == 0) high.erase(x);
  }
  else{
    lowsize--;
    low[x]--;
    if(low[x] == 0) low.erase(x);
  }
  balance();
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s", inputarr);
    if(inputarr[1] == 'o'){
      if(stkp == 0) printf("Invalid\n");
      else{
        printf("%d\n", stk[stkp-1]);
        del(stk[stkp-1]);
        stkp--;
      }
    }
    else if(inputarr[1] == 'e'){
      if(stkp == 0) printf("Invalid\n");
      else{
        printf("%d\n", median);
      }
    }
    else{
      scanf("%d", &stk[stkp++]);
      if(stk[stkp-1] <= median){
        low[stk[stkp-1]]++;
        lowsize++;
      }
      else{
        high[stk[stkp-1]]++;
        highsize++;
      }
      balance();
    }
  }
  return 0;
}
