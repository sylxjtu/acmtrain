#include <bits/stdc++.h>
using namespace std;

char digits[] = "0123456789ABCDEFGHIJ";

void ispali(int num, int base){
  vector<int> v;
  int x = num*num;
  while(x){
    v.push_back(x%base);
    x/=base;
  }
  int flag = 1;
  int fp = 0, tp = v.size() - 1;
  while(fp < tp){
    if(v[fp] != v[tp]){
      return;
    }
    fp++; tp--;
  }

  vector<int> v2;
  while(num){
    v2.push_back(num%base);
    num/=base;
  }
  for(int i = v2.size() - 1; i >= 0; i--){
    cout << digits[v2[i]];
  }
  cout << " ";
  for(int i = v.size() - 1; i >= 0; i--){
    cout << digits[v[i]];
  }
  cout << endl;

}

int main(){
  int b;
  cin >> b;
  for(int i = 1; i <= 300; i++){
    ispali(i,b);
  }
  return 0;
}
