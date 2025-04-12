//https://codeforces.com/contest/698/problem/F
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>
const ll mod = 1000000007ll;

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll n; cin >> n;
	vector<ll> a (n+1, 0);
	//lpdiv = largest prime divisor, ord = quantos multiplos esse valor tem até N
	//priord = quantos primos tem ordem i
	//fact = primos em sua fatoração, fact_prod = produto deles
	//association[i] = o primo i carrega a função de quem
	//whoWith[i] = a função i está associada a qual primo
	//mp[i] = quantos caras tem os primos que dão produto i (posições)
	vector<ll> association (n+1, 0), whoWith (n+1, 0);
	vector<ll> priord (n/2 + 1, 0), fatorial (n+1, 1);
	vector<vector<ll>> fact (n+1, vector<ll>());
	vector<ll> fact_prod (n+1, 1);
	vector<ll> lpdiv (n+1, 0);
	vector<ll> ord (n+1, 0);
	map<ll,ll> mp;

	for(ll i = 2; i <= n; i++){
		fatorial[i] = (fatorial[i-1] * i)%mod;
	}

	fact[1].push_back(1);
	fact_prod[1] = 1; ord[1] = 1;
	priord[1]++; lpdiv[1] = 1;
	mp[1]++;
	for(ll i = 2; i <= n; i++){
		ord[i] = (n/i);
		if(lpdiv[i] == 0){ //primo
			priord[ord[i]]++;
			lpdiv[i] = i;
			fact[i].push_back(i);
			fact_prod[i] *= i;
			for(ll j = 2*i; j <= n; j += i){
				lpdiv[j] = i;
			}
		} else { //composto
			fact[i] = fact[i/lpdiv[i]];
			fact_prod[i] = fact_prod[i/lpdiv[i]]; 
			if((i/lpdiv[i]) % lpdiv[i] != 0){
				fact[i].push_back(lpdiv[i]);
				fact_prod[i] *= lpdiv[i];
			}
		}
		mp[fact_prod[i]]++;
	}

	function<bool(ll,ll)> testFor = [&](ll pos, ll val) -> bool{
		ll xid = fact[pos].size()-1, yid = fact[val].size()-1;
		if(xid != yid) return false;
		while(xid >= 0 || yid >= 0){
			//próximo fator de pos já associado
			if(xid >= 0 && association[fact[pos][xid]] != 0){
				if(val % association[fact[pos][xid]] == 0){
					xid--;
					continue;
				} else {
					return false;
				}
			}
			//próximo fator de val já associado
			if(yid >= 0 && whoWith[fact[val][yid]] != 0){
				if(pos % whoWith[fact[val][yid]] == 0){
					yid--;
					continue;
				} else {
					return false;
				}
			}
			//nenhum fator associado, então podemos associar um no outro
			if(yid >= 0 && xid >= 0){
				if(ord[fact[pos][xid]] == ord[fact[val][yid]]){
					association[fact[pos][xid]] = fact[val][yid];
					priord[ord[fact[pos][xid]]]--;
					whoWith[fact[val][yid]] = fact[pos][xid];
					xid--; yid--;
					continue;
				} else {
					return false;
				}
			} else {
				return false;
			}
		}
		return true;
	};

	bool done = false;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(done) continue;
		if(a[i] != 0){
			done = !(testFor(i,a[i]));
			mp[fact_prod[i]]--;
		}
	}

	ll resp = 1;
	if(done){
		cout << 0 << "\n";
		return 0;
	} else {
		for(ll i = 1; i <= n/2; i++){
			while(priord[i] > 0){
				resp = (resp * priord[i])%mod;
				priord[i]--;
			}
		}
		for(auto x : mp){
			resp = (resp * fatorial[x.second])%mod;
		}
		cout << resp << "\n";
	}

	return 0;

}