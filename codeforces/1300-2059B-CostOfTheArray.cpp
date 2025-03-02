#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll,ll>

void solve(){

	ll n,k; cin >> n >> k;
	vector<ll> a (n+1, 0);
	ll r = 2;

	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		if(r == 2 && i > 1 && i <= n-k+2 && a[i] != 1){
			r = 1;
		}
	}

	if(k == n){
		for(ll i = 2; i <= n; i += 2){
			if(a[i] != i/2){
				cout << i/2 << "\n";
				return;
			}
		}
		cout << n/2 + 1 << "\n";
	} else {
		cout << r << "\n";
	}
	
	/*
	Se k = n:
	basta particionar elementos individuais e vê o primeiro que dá errado. se todos derem certo, é n/2 + 1.

	Se k != n: então note que uma forma de particionar o array seria {n-k+1 juntos, k-1 individuais}. Se algum dos n-k+2 primeiros for diferente de 1, podemos escolher todos os 1's antes dele e b começa com alguém diferente de 1, resultado em 1 como resposta.

	Agora, sabemos que n-k+2 primeiros elementos são 1, e além disso, k < n, ou seja, podemos fazer algum subconjunto com pelo menos 2 elementos.

	como os n-k+2 são todos 1, e n-k+2 >= 3, podemos sempre selecionar o primeiro para a e os dois próximos para b, fazendo a resposta ser 2.
	*/
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	ll t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}