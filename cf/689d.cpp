#include <cstdio>

int arr[200010];
int tree1[600000];
int tree2[600000];
int n;

int treemin(int l, int r, int curn) {
  printf("%d %d %d\n", l, r, curn);

  if (r - l == 1) {
    return tree1[curn] = arr[l];
  }
  else {
    return tree1[curn] =
      min(treemin(l, (l + r) / 2, curn * 2),
          treemin((l + r) / 2, r, curn * 2 + 1));
  }
}

int treemax(int l, int r, int curn) {
  printf("%d %d %d\n", l, r, curn);

  if (r - l == 1) {
    return tree2[curn] = arr[l];
  }
  else {
    return tree2[curn] =
      max(treemax(l, (l + r) / 2, curn * 2),
          treemax((l + r) / 2, r, curn * 2 + 1));
  }
}

int findmin(int l, int r, int curl, int curr, int curn) {
  int mid = (curl + curr) / 2;

  if ((l == curl) && (r == curr)) return tree1[curn];

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

int findmax(int l, int r, int curl, int curr, int curn) {
  int mid = (curl + curr) / 2;

  if ((l == curl) && (r == curr)) return tree2[curn];

  if (r <= mid) {
    return findmax(l, r, curl, mid, curn * 2);
  }

  if (l >= mid) {
    return findmax(l, r, mid, curr, curn * 2 + 1);
  }
  else {
    return max(findmax(l, mid, curl, mid, curn * 2),
               findmax(mid, r, mid, curr, curn * 2 + 1));
  }
}

int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  treemax(0, n, 1);
  for(int i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  treemin(0, n, 1);
  for(int i = 0; i < n; i++){
    int rmax, rmin, a = i+1, b = n+1;
    while(b - a > 1){
      int mid = (rmax + rmin) / 2;
      if(findmax(i, ))
    }
  }
}
