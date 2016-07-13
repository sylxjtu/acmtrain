#include <cstdio>
#include <algorithm>
using namespace std;

int arr[1000];
int tree[1000];

int treemin(int l, int r, int curn) {
  printf("%d %d %d\n", l, r, curn);

  if (r - l == 1) {
    return tree[curn] = arr[l];
  }
  else {
    return tree[curn] =
      min(treemin(l, (l + r) / 2, curn * 2),
          treemin((l + r) / 2, r, curn * 2 + 1));
  }
}

int findmin(int l, int r, int curl, int curr, int curn) {
  int mid = (curl + curr) / 2;

  if ((l == curl) && (r == curr)) return tree[curn];

  if (r <= mid) {
    return findmin(l, r, curl, mid, curn * 2);
  }

  if (l >= mid) {
    return findmin(l, r, mid, curr, curn * 2 + 1);
  }
  else {
    return min(findmin(l, mid, curl, mid, curn * 2),
               findmin(mid, r, mid, curr, curn * 2 + 1));
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  treemin(0, n, 1);

  while (1) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", findmin(x, y, 0, n, 1));
  }
}
