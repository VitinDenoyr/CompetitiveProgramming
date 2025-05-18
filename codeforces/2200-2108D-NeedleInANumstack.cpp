//https://codeforces.com/problemset/problem/2108/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n, k; cin >> n >> k;
	if(n == 2*k){
		cout << "! " << k << " " << k << endl;
		return;
	}

	vector<int> vA (k+1, 0), vB (k+1, 0);
	for(int i = 1; i <= k; i++){ 
		cout << "? " << i << endl;
		cin >> vA[i%k];
		cout << "? " << n + 1 - i << endl;
		cin >> vB[(n+1-i)%k];
	}

	vector<int> d(k+1, 0); //restos com diferença de [1, r] , 0 = k o último.
	for(int ir = 1; ir <= k; ir++){
		d[ir%k] = d[(ir-1)%k];
		if(vA[ir%k] != vB[ir%k]){
			d[ir%k]++;
		}
	}

	function<int(int,int)> count = [&](int x, int y) -> int{ 
		int x0 = (x - x%k - (x%k==0)*k), y0 = (y - y%k - (y%k==0)*k);
		int s1 = d[0]*((y0 - x0)/k);
		int goods = d[y%k];
		int bads = (x-1+k)%k == 0 ? 0 : d[(x-1+k)%k];
		return s1 + goods - bads;
	};
	
	int l = k+1, r = n-k;
	if(count(l,r) == 0){
		cout << "! " << -1 << endl;
		return;
	}

	while(l <= r){
		int midsum = (count(l,r)+2)/2;
		int l0 = l, r0 = r;
		while(l0 < r0){
			int mid0 = (l0+r0)/2;
			if(count(l, mid0) >= midsum){
				r0 = mid0;
			} else {
				l0 = mid0 + 1;
			}
		}
		
		cout << "? " << l0 << endl;
		int answer = 0; cin >> answer;
		if(answer == vA[l0%k]){
			if(l0 == l && count(l,r) == 1){
				if(r == l){
					cout << "! " << l0 << " " << n - l0 << endl;
					return;
				} else {
					cout << "! " << -1 << endl;
					return;
				}
			}
			l = l0;
		} else {
			if(l == l0){
				cout << "! " << l0-1 << " " << n - (l0-1) << endl;
				return;
			} else if(count(l,l0-1) == 0){
				cout << "! " << -1 << endl;
				return;
			}
			r = l0-1;
		}
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}