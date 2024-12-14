//https://codeforces.com/contest/2037/problem/D
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){
	int n,m,L; cin >> n >> m >> L; //nlog nlog 10^9
	vector<pii> holes (n+1, {0,0});
	vector<int> hsize (n+1, 0);
	vector<pii> powers (m+1, {0,0});
	
	for(int i = 0; i < n; i++){
		int l,r; cin >> l >> r;
		holes[i] = {l,r};
		hsize[i] = (r - l + 1);
	}
	holes[n] = {L+10,0};
	hsize[n] = L;
	
	for(int i = 0; i < m; i++){
		ll x,v; cin >> x >> v;
		powers[i] = {x,v};
	}
	powers[m] = {L+10,0};

	vector<pii> events;
	int nxtH = 0, nxtP = 0;
	while(holes[nxtH].first <= L || powers[nxtP].first <= L){
		if(holes[nxtH].first <= powers[nxtP].first){
			events.push_back({holes[nxtH].first, holes[nxtH].second});
			nxtH++;
		} else {
			events.push_back({powers[nxtP].first, -powers[nxtP].second});
			nxtP++;
		}
	}

	priority_queue<ll, vector<ll>, less<ll>> pq;
	
	int qtPowers = 0, currPower = 1;
	for(int i = 0; i < events.size(); i++){
		if(events[i].second < 0){ //Power
			events[i].second *= -1;
			pq.push(events[i].second);
		} else { //Hole
			if(currPower <= (events[i].second - events[i].first + 1)){
				while(currPower <= (events[i].second - events[i].first + 1)){
					if(pq.empty()){
						cout << -1 << "\n";
						return;
					}
					currPower += pq.top();
					pq.pop();
					qtPowers++;
				}
			}
		}
	}
	cout << qtPowers << "\n";
}

int main(){

	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}