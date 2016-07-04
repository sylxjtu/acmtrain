#include <bits/stdc++.h>
using namespace std;

int mat[100][100];

struct vetice{
    int n;
    int distance;
    vetice(int x, int y): n(x), distance(y) {}
};

bool operator< (const vetice& v1, const vetice& v2){
    return v1.distance > v2.distance;
}

priority_queue<vetice> pq;
int discnt[100];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < 100; i++){
        for (int j = 0; j < 100; ++j) {
            mat[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < 100; ++i) {
        discnt[i] = INT_MAX;
    }
    for(int i = 0; i < n; i++){
        char a, b;
        int c;
        scanf(" %c %c %d", &a, &b, &c);
        if(a == b) continue;
        mat[a-'A'][b-'A'] = min(mat[a-'A'][b-'A'], c);
        mat[b-'A'][a-'A'] = min(mat[b-'A'][a-'A'], c);
    }
    for(int i = 0; i < 100; i++){
        if(mat['Z'-'A'][i] != INT_MAX){
            pq.push(vetice(i,mat['Z'-'A'][i]));
        }
    }
    while(!pq.empty()){
        int x = pq.top().n;
        int dis = pq.top().distance;
        discnt[x] = dis;
        pq.pop();

        if(x + 'A' >= 'A' && x + 'A' < 'Z'){
            cout << char(x+'A') << " " << dis << endl;
            return 0;
        }

        for(int i = 0; i < 100; i++){
            if(mat[x][i] != INT_MAX){
                if(dis+mat[x][i] < discnt[i])
                    pq.push(vetice(i,dis+mat[x][i]));
            }
        }
    }
    return 0;
}
