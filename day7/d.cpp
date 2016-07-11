#include <cstdio>
#include <queue>
using namespace std;

struct query{
  int interval;
  int nextTrigger;
  int num;
  bool operator< (const query& q2) const{
    return nextTrigger > q2.nextTrigger || (nextTrigger == q2.nextTrigger && num > q2.num);
  }
  query(int n, int t): interval(t), nextTrigger(t), num(n){}
  query(int n, int t, int i): interval(i), nextTrigger(t), num(n){}
};

char str[20];

int main(){
  priority_queue<query> qq;
  while(1){
    scanf("%s", str);
    if(str[0] == '#') break;
    int x, y;
    scanf("%d%d", &x, &y);
    qq.push(query(x, y));
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int x = qq.top().nextTrigger, y = qq.top().num, z = qq.top().interval;
    printf("%d\n", y);
    qq.pop();
    qq.push(query(y, x+z, z));
  }
}
