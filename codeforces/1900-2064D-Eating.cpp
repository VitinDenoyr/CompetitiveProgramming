//https://codeforces.com/contest/2064/problem/D
#include <bits/stdc++.h>
using namespace std;
#define DEBUG if(0)
#define ll long long
#define pii pair<int,int>

struct PrefXor {
	int len; vector<int> v;
	PrefXor(int _n, vector<int>& a){
		len = _n;
		v = vector<int> (_n + 1, 0);
		for(int z = 1; z <= len; z++){
			v[z] = v[z-1] ^ a[z];
		}
	}

	int query(int left, int right){
		return (v[right]^v[left-1]);
	}
};

//v[b][k] -> Quais os dois últimos caras no intervalo [1, k] que tem o maior bit como o b° ou acima
struct CountMSB {
	int len; vector<vector<pii>> v;
	vector<int> wall;
	CountMSB(int _n, vector<int>& a){
		len = _n;
		v = vector<vector<pii>>(31, vector<pii>(_n+1));
		wall = vector<int> (31, 0);
		int comp = 1;
		for(int b = 1; b <= 30; b++){
			stack<int> memo;
			memo.push(0); v[b][0] = {0,0};
			for(int i = 1; i <= len; i++){
				if(a[i] >= 2*comp) wall[b] = i;
				if((a[i] & comp) != 0){
					v[b][i] = {i, memo.top()};
					memo.push(i);
				} else {
					v[b][i] = v[b][i-1];
				}
			}
			comp *= 2;
		}
	}
};

void solve(){

	int n,q; cin >> n >> q;
	vector<int> a (n+1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	CountMSB vec (n,a);
	PrefXor prf (n,a);

	for(int ij = 1; ij <= q; ij++){
		int x0; cin >> x0;
		int k = 0, kv = 1;
		while(kv <= x0){
			k++;
			kv *= 2;
		}

		int barrier = vec.wall[k], alive = n;
		DEBUG cout << " --- new test --- \n";
		while(k >= 1){
			//Se tenho o bit:
			//	Come os slimes com maior bit < k em sequência
			//	Se tiver um slime com maior bit k, corta com ele e tenta comer ele. Se tiver mais, então o próximo é uma barreira
			//Se nao tenho o bit:
			//	Se tiver um slime com maior bit k, ele é uma barreira
			//
			DEBUG cout << "bit: " << k << "\n";
			if(alive == barrier) break;
			if((x0 & (1<<(k-1))) != 0){
				DEBUG cout << "tenho\n";
				pii res = vec.v[k][alive];
				DEBUG cout << "barreira: " << barrier << " -> ";
				if(res.second > 0) barrier = max(res.second, barrier);
				DEBUG cout << barrier << "\n";
				DEBUG cout << "forte mais a esquerda: " << res.first << "\n";
				int canEat = min(alive - res.first, alive - barrier);
				x0 ^= prf.query(alive-canEat+1,alive);
				int mask = (1<<k)-1;
				DEBUG cout << "fiquei com " << x0 << "\n";
				if(k == 1){
					canEat = alive - barrier;
					DEBUG cout << "mas na vdd posso comer " << canEat << " caras\n";
				}
				DEBUG cout << "comi " << canEat << "\n";
				alive -= canEat;
			} else {
				DEBUG cout << "nao tenho\n";
				pii res = vec.v[k][alive];
				if(res.first > 0) barrier = max(res.first, barrier);
				if(k == 1){
					int canEat = alive - barrier;
					DEBUG cout << "mas " << canEat << " caras tbm nao tem\n";
					alive -= canEat; 
				}
			}
			k--;
		}
		cout << n - alive << " \n"[ij==q];
	}
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}