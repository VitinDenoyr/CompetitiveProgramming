#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define ppii pair<pii,pii>

bool compary(ppii a, ppii b){
	if(a.second.first < b.second.first) return true;
	return false;
}

vector<queue<int>> ocur;
vector<vector<int>> divs;

void solve(){

	int n,q; cin >> n >> q;
	vector<int> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		ocur[a[i]].push(i);
	}

	vector<ppii> queries;
	vector<ll> ans (q+1, 0);
	for(int i = 1; i <= q; i++){
		queries.push_back({{i,0},{0,0}});
		cin >> queries[i-1].first.second >> queries[i-1].second.first >> queries[i-1].second.second;
	}
	sort(queries.begin(),queries.end(),compary);

	for(ppii qr : queries){
		int l = qr.second.first, r = qr.second.second;
		int id = qr.first.first, k = qr.first.second;
		int lastlowest = l;

		while(k > 1){
			//acha proxima ocorrencia
			int lowest = r+1;
			for(int div : divs[k]){
				while(!ocur[div].empty()){
					int nx = ocur[div].front();
					if(nx < l){
						ocur[div].pop();
					} else if(nx <= r){
						lowest = min(lowest, nx);
						break;
					} else {
						break;
					}
				}
			}
			if(lowest == r+1){
				ans[id] += (ll)(r - lastlowest + 1)*(ll)(k-1);
				break;
			}

			ans[id] += (ll)k*(ll)(lowest-lastlowest);
			k /= a[lowest];
			lastlowest = lowest;
		}
		ans[id] += (ll)(r - lastlowest + 1);
	}

	for(int i = 1; i <= q; i++){
		cout << ans[i] << "\n";
	}

	for(int i = 1; i <= n; i++){
		if(!ocur[a[i]].empty()) ocur[a[i]].pop();
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);

	ocur = vector<queue<int>> (100002, queue<int>());
	divs = vector<vector<int>> (100002, vector<int>()); //divisores exceto 1

	for(int i = 2; i <= 100000; i++){
		for(int j = i; j <= 100000; j += i){
			divs[j].push_back(i);
		}
	}

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}