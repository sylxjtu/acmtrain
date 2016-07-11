#include <iostream>
using namespace std;
int ev, od;

int main(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    od += x%2;
    ev += (x+1)%2;
  }
  cout << od << " " << ev << endl;
}
