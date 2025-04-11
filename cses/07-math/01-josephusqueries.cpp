#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int q; cin >> q;
	
	for(int i = 1; i <= q; i++){
		int n,k;
		cin >> n >> k;

		int rage = 0, it = 0, r = 1;
		while(k > ((n+rage)/2) && (n > 1)){
			int deaths = (n+rage)/2;
			r += rage * (1<<(it));
			if(n%2) rage = 1 - rage;
			k -= deaths;
			n -= deaths;
			it++;
		}
		if(n == 1){
			cout << r << "\n";
		} else {
			cout << (2*k-1-rage)*(1<<it) + r << "\n";
		}

	}


	return 0;

}