#include <bits/stdc++.h>
using namespace std;

int rescueCnt[510];
int edges[510][510];

int dis[510];
int ways[510];
int maxRescue[510];
int parents[510];

struct status {
  int node;
  int dis;
  bool operator<(const status& s2) const {
    return dis > s2.dis;
  }

  status(int n, int d) : node(n), dis(d) {}
};

int main() {
  int n, m, s, d;

  cin >> n >> m >> s >> d;

  for (int i = 0; i < n; i++) {
    dis[i] = INT_MAX / 4;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      edges[i][j] = INT_MAX / 4;
    }
  }

  for (int i = 0; i < n; i++) {
    cin >> rescueCnt[i];
  }

  for (int i = 0; i < m; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges[x][y] = edges[y][x] = z;
  }
  dis[s] = 0;
  priority_queue<status> pq;
  pq.push(status(s, dis[s]));
  maxRescue[s] = rescueCnt[s];
  int flag = 0;

  while (!pq.empty()) {
    int nd = pq.top().node, di = pq.top().dis;
    pq.pop();

    if (flag && (flag < di)) break;

    if (!flag && (nd == d)) flag = di;

    if (di > dis[nd]) continue;

    // printf("nd = %d, di = %d\n", nd, di);

    for (int i = 0; i < n; i++) {
      if (i == nd) continue;

      if (di + edges[nd][i] < dis[i]) {
        ways[i]      = 1;
        maxRescue[i] = -1;
        dis[i]       = di + edges[nd][i];
      }
      else if (di + edges[nd][i] == dis[i]) {
        ways[i]++;
      }
      else {
        continue;
      }

      if (maxRescue[nd] + rescueCnt[i] > maxRescue[i]) {
        parents[i]   = nd;
        maxRescue[i] = maxRescue[nd] + rescueCnt[i];
      }
      pq.push(status(i, dis[nd] + edges[nd][i]));
    }
  }
  printf("%d %d\n", ways[d], maxRescue[d]);
  stack<int> stk;
  stk.push(d);
  int x = d;
  while(parents[x] != s){
    stk.push( x = parents[x] );
  }
  cout << s;
  while(!stk.empty()){
    cout << " " << stk.top();
    stk.pop();
  }
  cout << endl;
  return 0;
}
