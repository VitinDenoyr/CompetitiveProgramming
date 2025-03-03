//https://codeforces.com/problemset/problem/2060/G
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n, qtinv = 0; cin >> n;
	vector<int> a (n+1, 0), b (n+1, 0), c (n+2, 0), d (n+2, 0);
	vector<int> part (2*n+1, 0), fixed (2*n+1, 0), inRight (2*n+1, 0);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		part[a[i]] = b[i]; part[b[i]] = a[i];
	}

	bool flexible = false; int tot = 0;

	//Posiciona 1 e o parceiro de 1 como início dos dois arrays
	int nx = 2;
	c[1] = 1; d[1] = part[1];
	fixed[1] = 1; fixed[part[1]] = 1;
	inRight[part[1]] = 1;

	//Assume que todos anteriores já estão posicionados sem problema.
	for(int i = 2; i <= 2*n; i++){
		if(!fixed[i]){ //Primeiro não posicionado, então coloca em C pois qualquer outro não posicionado é maior
			if(nx*2 == i+1){ //Bloco anterior completo de tamanho ((nx-1) - tot)
				if((nx-1-tot)%2 == 1) flexible = true;
				tot = nx-1;
			}
			c[nx] = i;
			d[nx] = part[i];
			fixed[i] = 1; fixed[part[i]] = 1;
			inRight[part[i]] = 1;

			//Falha pra colocar, é impossível.
			if(c[nx] < c[nx-1] || d[nx] < d[nx-1]){
				cout << "NO\n";
				return;
			}

			nx++;
		}
	}

	for(int i = 1; i <= n; i++){
		if(inRight[a[i]]) qtinv++;
	}

	//Após posicionar todos, vai tentar ver se essa ordenação é factível por qt. inv.
	if(flexible || (n%2 == 1) || (qtinv%2 == 0)){
		cout << "YES\n";
	} else {
		cout << "NO\n";
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