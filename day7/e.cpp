#include <cstdio>
#include <stack>
using namespace std;

stack<int> s;

int main() {
  int t;
  scanf("%d", &t);
  for(int kase = 0; kase < t; kase++){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
      int x;
      scanf("%d", &x);
      while(s.size() < x - i){
        s.push(0);
      }
      int t = ++s.top();
      printf("%d%s", s.top(), i == n-1 ? "\n" : " ");
      s.pop();
      if(!s.empty()) s.top()+=t;
    }
  }
  return 0;
}
