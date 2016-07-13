#include <bits/stdc++.h>
using namespace std;

char n[100];

int main(){
  scanf("%s", n);
  int l = strlen(n);
  double buff = 1;
  if(n[0] == '-') buff+=.5;
  if((n[l-1] - '0') % 2 == 0) buff*=2;
  int a = 0, b = 0;
  for(int i = 0; i < l; i++){
    if(isdigit(n[i])){
      b++;
      if(n[i] == '2'){
        a++;
      }
    }
  }
  printf("%.2f%%\n", buff * a / b * 100);
  return 0;
}
