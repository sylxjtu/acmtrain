#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

P rectans[4];
int minsz = INT_MAX;
set<P> minst;
P insp[100000];
int inspdir[100000];
int inspp;
int valid[100000];
vector<pair<P,P>> recs;

void isrealok(int mask, int curmx, int curmy, int n){
  if(n == 4){
    if(curmx*curmy < minsz){
      minsz = curmx*curmy;
      minst.clear();
      minst.insert(curmx < curmy ? P(curmx, curmy) : P(curmy, curmx));
    }
    else if(curmx*curmy == minsz){
      minst.insert(curmx < curmy ? P(curmx, curmy) : P(curmy, curmx));
    }
  }
  else{
    int ix = inspp;
    for(int i = 0; i < inspp; i++){
      if(valid[i]){
        valid[i] = 0;
        int dx = (mask >> n) & 1 ? rectans[n].second : rectans[n].first;
        int dy = (mask >> n) & 1 ? rectans[n].first : rectans[n].second;
        int x = insp[i].first;
        int y = insp[i].second;
        for(auto &i: recs){
          int ax = i.first.first, bx = i.second.first, ay = i.first.second, by = i.second.second;
          if(x < bx && x+dx > ax && y < by && y+dy > ay){
            //cout << "dx" << dx << " dy" << dy << endl;
            //cout << y << " " << x << " " << ax << " " << bx << " " << ay << " " << by << endl;
            int tx = x, ty = y;
            insp[inspp] = P(bx, y);
            valid[inspp++] = 1;
            insp[inspp] = P(x, by);
            valid[inspp++] = 1;
            isrealok(mask, curmx, curmy, n);
            inspp = ix;
            goto cont;
          }
        }
        insp[inspp] = P(x+dx, y);
        valid[inspp++] = 1;
        insp[inspp] = P(x, y+dy);
        valid[inspp++] = 1;
        recs.push_back(make_pair(P(x,y),P(x+dx,y+dy)));
        isrealok(mask, max(curmx,x+dx), max(curmy,y+dy), n+1);
        recs.pop_back();
        inspp = ix;
        cont:;
        valid[i] = 1;
      }
    }
  }
}

void checkminsz(){
  for(int i = 0; i < 1<<4; i++){
    inspp = 0;
    insp[inspp++] = P(0, 0);
    valid[0] = 1;
    isrealok(i, 0, 0, 0);
  }
}

int main(){
  for(int i = 0; i < 4; i++){
    cin >> rectans[i].first >> rectans[i].second;
  }
  for (size_t i = 0; i < 24; i++) {
    //cout << i << endl;
    checkminsz();
    next_permutation(rectans, rectans+4);
  }
  cout << minsz << endl;
  for(auto &i: minst){
    cout << i.first << " " << i.second << endl;
  }
  return 0;
}
