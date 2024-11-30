#include <bits/stdc++.h>
using namespace std;
#define ll int
#define pll pair<ll,ll>
#define INF 1000000008
 
bool comp(pll a, pll b){
	if(a.second == b.second) return a.first > b.first;
	return a.second < b.second;
}
 
int main(){
 
	vector<pll> v;
	ll n,k,mvs,mve; cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> mvs >> mve;
		v.push_back({mvs,mve});
	}
	sort(v.begin(),v.end(),comp);
 
	multiset<ll> fin; 
	int resp = 0;
    for(int i = 0; i < k; i++){
        fin.insert(-1);
    }
 
	for(int i = 0; i < n; i++){
		if(v[i].first >= *fin.begin()){
            auto ans = fin.upper_bound(v[i].first);
            if(ans != fin.begin()){
                auto prv = prev(ans);
                fin.erase(prv);
                fin.insert(v[i].second);
                resp++;
            }
        }
	}
	cout << resp << "\n";
 
	return 0;
}