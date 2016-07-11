#include <bits/stdc++.h>
#include <cmath>
using namespace std;

#define EPS 1e-5
#define PI (acos(-1))

inline sign(double x){
  if(x > EPS) return 1;
  if(x < -EPS) return -1;
  else return 0;
}

struct Point{
  double x;
  double y;
  Point(double x = 0, double y = 0): x(x), y(y){}
  bool operator< (const Point& p2) const{
    if(sign(x-p2.x) == -1) return true;
    else if(sign(x-p2.x) == 0 && sign(y-p2.y) == -1) return true;
    return false;
  }
  double operator* (const Point& p2) const{
    return x * p2.y - y * p2.x;
  }
  Point operator- (const Point& p2) const{
    return Point(x - p2.x, y - p2.y);
  }
  double len2() const{
    return x*x + y*y;
  }
  double len() const{
    return sqrt(len2());
  }
};

int diameter(vector<Point>& v){
  double cnt = 0;
  for(int i = 0; i < v.size(); i++){
    cnt += v[i].len();
  }
  return abs(cnt);
}

void frame(const vector<Point>& v, vector<Point>& ret){
  Point edgex = v[1] - v[0];
  ret.push_back(edgex);
  int n = 0;
  for(int i = 2; i < v.size(); i++){
    if(sign(edgex*(v[i] - v[n])) == -1){
      while(sign(edgex*(v[i] - v[n])) == -1 && n>=0){
        edgex = v[i] - v[n];
        ret.pop_back();
        n--;
      }
      if(n < 0) n = 0;
    }
    else{
      edgex = v[i] - v[i-1];
      n = i-1;
    }
    ret.push_back(edgex);
  }
  edgex = v[v.size() - 1] - v[v.size() - 2];
  ret.push_back(edgex);
  for(int i = v.size() - 3; i >= 0; i--){
    int n = i+2;
    if(sign(edgex*(v[i] - v[n])) == -1){
      while(sign(edgex*(v[i] - v[n])) == -1 && n<=v.size()-1){
        ret.pop_back();
        edgex = v[i] - v[n];
        n++;
      }
      if(n > v.size()-1) n = v.size()-1;
    }
    else{
      edgex = v[i] - v[i+1];
      n = i+1;
    }
    ret.push_back(edgex);
  }
}

int main(){
  int ks;
  cin >> ks;
  for(int i = 0; i < ks; i++){
    int n, dis;
    cin >> n >> dis;
    vector<Point> v;
    for(int j = 0; j < n; j++){
      int a, b;
      cin >> a >> b;
      v.push_back(Point(a, b));
    }
    sort(v.begin(), v.end());
    vector<Point> frv;
    frame(v, frv);
    if(i != 0) printf("\n");
    printf("%.0lf\n", diameter(frv)+dis*PI+.5);
  }
  return 0;
}
