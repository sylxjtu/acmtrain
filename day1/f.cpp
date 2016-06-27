#include <bits/stdc++.h>
using namespace std;

char digits[] = "0123456789ABCDEFGHIJ";

bool ispali(int num, int base){
  vector<int> v;
  while(num){
    v.push_back(num%base);
    num/=base;
  }
  int fp = 0, tp = v.size() - 1;
  while(fp < tp){
    if(v[fp] != v[tp]){
      return false;
    }
    fp++; tp--;
  }
  return true;
}

int isthatpali(int num){
  int cnt = 2;
  for(int i = 2; i <= 10 && cnt; i++){
    if(ispali(num, i)) cnt--;
  }
  if(!cnt) cout << num << endl;
  return !cnt;
}

int main(){
  int n, s;
  cin >> n >> s;
  for(int i = s+1; n; i++){
    if(isthatpali(i)){
      n--;
    }
  }
  return 0;
}
