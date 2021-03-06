#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
struct money {
	long long price;
	int amount;
};
bool operator< (const money& m1, const money& m2) {
	return m1.price > m2.price;
}
money mv[24];
int rat[20];
int main() {
	int n, cnt = 0;
	long long c;
	cin >> n >> c;
	for(int i = 0; i < n; i++) {
		cin >> mv[i].price >> mv[i].amount;
	}
	sort(mv, mv+n);
	int i;
	for(i = 0; i < n; i++) {
		if(mv[i].price >= c) {
			cnt += mv[i].amount;
		} else {
			break;
		}
	}
	int mi = 0;
	while(1) {
		long long ctmp = c;
		mi = INT_MAX;
		for(int j = 0; j < n; j++) {
			rat[j] = 0;
		}
		for(int j = i; j < n; j++) {
			if(mv[j].amount) {
				rat[j] = min( (int)(ctmp / mv[j].price), mv[j].amount );
				ctmp -= rat[j] * mv[j].price;
			}
		}
		if(ctmp) {
			for(int j = n-1; j >= i; j--) {
				if(mv[j].amount) {
					if(rat[j] + 1 + ctmp / mv[j].price <= mv[j].amount){
						rat[j] += 1 + ctmp / mv[j].price;
						ctmp = 0;
						break;
					}
				}
			}
		}
		if(ctmp) {
			break;
		}
		for(int j = i; j < n; j++) {
			if(mv[j].amount && rat[j] && mv[j].amount / rat[j]) {
				mi = min(mi, mv[j].amount / rat[j]);
			}
		}
		if(mi == INT_MAX) {
			break;
		}
		for(int j = i; j < n; j++) {
			if(mv[j].amount) {
				mv[j].amount -= mi * rat[j];
			}
		}
		cnt += mi;
		//cout << "mi " << mi << endl;
		//for(int j = 0; j < n; j++){
		//	cout << "j " << j << " p " << mv[j].price << " a " << mv[j].amount << endl;
		//}
	}
	cout << cnt << endl;
	return 0;
}
