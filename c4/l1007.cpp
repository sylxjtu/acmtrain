#include <bits/stdc++.h>
using namespace std;

char strs[][10] = {
"fu",
"ling",
"yi",
"er",
"san",
"si",
"wu",
"liu",
"qi",
"ba",
"jiu",
};

char goodchar[] = "-0123456789";

int main(){
  char c;
  int flag = 0;
  while(cin >> c){
    for(int i = 0; goodchar[i]; i++){
      if(goodchar[i] == c){
        if(flag) cout << " "; else flag = 1;
        cout << strs[i];
        goto cont;
      }
    }
    cout << endl;
    return 0;
    cont:;
  }
  return 0;
}
