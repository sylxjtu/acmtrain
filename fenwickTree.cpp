const int maxn = 10010;

int bit[maxn+1];
int arr[maxn+1];

inline int lowbit(int x){
  return x&(-x);
}

void build(){
  for(int i = 1; i <= maxn; i++){
    bit[i] = arr[i];
    for(int j = i - 1; j > i - lowbit(i); j--){
      bit[i] += arr[j];
    }
  }
}

void edit(int i, int delta){
  for(int j = i; j <= maxn; j += lowbit(j)){
    bit[j] += delta;
  }
}

int sum(int k){
  int ans = 0;
  for(int i = k; i > 0; i -= lowbit(i)){
    ans += bit[i];
  }
  return ans;
}

int main(){
  return 0;
}
