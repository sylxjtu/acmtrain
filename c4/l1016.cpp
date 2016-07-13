#include <bits/stdc++.h>
using namespace std;

char m[] = "10X98765432";
int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char tmp[100];

int main(){
  int n, allpass = 1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s", &tmp);
    int sum = 0;
    for(int j = 0; j < 17; j++){
      if(!isdigit(tmp[j])){
        printf("%s\n", tmp);
        allpass = 0;
        goto cont;
      }
      else{
        sum += (tmp[j] - '0') * weight[j];
      }
    }
    if(tmp[17] != m[sum%11]){
      printf("%s\n", tmp);
      allpass = 0;
      goto cont;
    }
    cont:;
  }
  if(allpass) printf("All passed\n");
  return 0;
}
