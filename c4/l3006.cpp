#include <bits/stdc++.h>
#include <cmath>
using namespace std;

const double eps = 1e-5;

struct epsDouble{
  double val;
  epsDouble(double v): val(v){}
  bool operator == (const epsDouble& e2) const {
    return fabs(val - e2.val) < eps;
  }
  bool operator == (double d) const{
    return fabs(val - d) < eps;
  }
  bool operator < (const epsDouble& e2) const {
    return val - e2.val < -eps;
  }
};

struct P{
  double x;
  double y;
  P(double x, double y) : x(x), y(y){}
  P operator- (const P& p2) const{
    return P(x - p2.x, y - p2.y);
  }
  double dist() const{
    return sqrt(x*x+y*y);
  }
};

vector<P> v1, v2;
vector<epsDouble> a1, a2;
vector<epsDouble> l1, l2;

double operator* (const P &a, const P &b){
  return a.x*b.x + a.y*b.y;
}

double vcos (const P &a, const P &b){
  return a*b / (a.dist()*b.dist());
}

int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    
  }
  return 0;
}
