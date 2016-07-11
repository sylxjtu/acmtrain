#include <cstdio>
#include <iostream>
using namespace std;

int main(){
  int h, m;
  scanf("%d:%d", &h, &m);
  if( h >= 0 && h<12 || (h == 12 && m == 0) ){
    printf("Only %02d:%02d.  Too early to Dang.\n", h, m);
  }
  else{
    h += (m != 0) - 12;
    for(int i = 0; i < h; i++){
      cout << "Dang";
    }
    cout << endl;
  }
  return 0;
}
