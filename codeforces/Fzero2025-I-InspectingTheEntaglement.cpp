//https://codeforces.com/gym/105925/problem/I
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppll pair<pll,pll>
const ll INF = 100000000000000000ll;
const ppll UNDEF = {{-INF,-1},{-INF,-1}};
const ppll IMPOS = {{-INF+1,-1},{-INF+1,-1}};

void solve(){

	int n,T; cin >> n >> T;
	vector<vector<ll>> a (n+1, vector<ll>(T+1, 0));
	for(int i = 1; i <= n; i++){
		for(int it = 1; it <= T; it++){
			cin >> a[i][it];
		}
	}
	int l,u; cin >> l >> u;
	
	//Número mínimo de usos de sensores para que seja possível garanir >= T de tempo
	int mini = 0, maxi = 0;
	while(mini*u < T){
		mini++;
	}
	//Número máximo de usos de sensores para que seja possível garantir <= T de tempo.
	while(maxi*l <= T){
		maxi++;
	}
	maxi--;

	//Se tivermos entre [mini, maxi] usos de sensores, então consigo garantir T de tempo de alguma forma ao menos.
	//Caso contrário, é impossível conseguirmos.
	if(mini > maxi){
		cout << -1 << "\n";
		return;
	}

	function<bool(ppll,ppll)> dif = [&](ppll a, ppll b) -> bool {
		if(a.first.first != b.first.first) return true;
		if(a.second.first != b.second.first) return true;
		if(a.first.second != b.first.second) return true;
		if(a.second.second != b.second.second) return true;
		return false;
	};

	vector<ppll> dp (T+1, UNDEF); dp[0] = {{0,0},{-INF,-1}};
	function<ppll(int)> calc = [&](int t) -> ppll {
		//cout << "Calc " << t << "\n";
		if(dif(dp[t],UNDEF)) return dp[t];
		if(t < l) return UNDEF;
		//cout << "->\n";
		for(int op = 1; op <= n; op++){
			ll sum = 0;
			for(int i = 1; i < l; i++){
				sum += a[op][t+1-i];
			}
			for(int i = l; i <= min(t,u); i++){
				sum += a[op][t+1-i];

				ppll alter = calc(t-i);
				pll nw;
				if(alter.first.second == op){
					nw = alter.second;
				} else {
					nw = alter.first;
				}
				nw.first += sum;
				nw.second = op;

				if(nw.second == dp[t].second.second){
					dp[t].second.first = max(dp[t].second.first, nw.first);
					if(dp[t].first.first < dp[t].second.first) swap(dp[t].first, dp[t].second);
				} else if(nw.second == dp[t].first.second){
					dp[t].first.first = max(dp[t].first.first, nw.first);
				} else {
					if(nw.first >= dp[t].first.first){
						dp[t] = {nw, dp[t].first};
					} else if(nw.first > dp[t].second.first){
						dp[t].second = nw;
					}
				}
				//cout << "{" << dp[t].first.first << "," << dp[t].first.second << "} , {" << dp[t].second.first << "," << dp[t].second.second << "}\n";
				//cout << i << " x " << t << " , " << u << "\n"; 
			}
		}

		if(dp[t] == UNDEF){
			//cout << "Impossible\n";
			dp[t] = IMPOS;
		}
		//cout << "Return Calc " << t << "\n"; 
		return dp[t];
	};
	cout << calc(T).first.first << "\n";

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}