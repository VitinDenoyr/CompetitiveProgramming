#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define MAXN 2505
#define INF 100000000000000007
 
ll n,m;
vector<vector<ll>> ares;
ll dist[MAXN], prv[MAXN];
vector<int> pathway;
 
int main(){
 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b,c;
		cin >> a >> b >> c;
		ares.push_back({a,b,c});
	}
	
	bool hasCycle = 0; int node = 0;
	for(int r = 1; r <= n; r++){
		node = 0;
		for(vector<ll> ar : ares){
			if(dist[ar[0]] + ar[2] < dist[ar[1]]){
				dist[ar[1]] = dist[ar[0]] + ar[2];
				prv[ar[1]] = ar[0];
				node = ar[1];
			}
		}
	}
	
	if(node == 0){
		cout << "NO\n";
	} else {
		/* node é encontrado na N-ésima iteração. A cada iteração de prev[], pode ocorrer o seguinte:
			i) se estamos com o correspodente da K-ésima iteração, o prev será o da (K-1)-ésima iteração;
			ii) se estamos com o correspodente da K-ésima iteração, o prev será o da J-ésima iteração onde J > K-1, ou seja, alguma modificação substituiu o prev;
			Isso mostra que podemos executar prev[] n vezes. Note que como temos n+1 vértices vistos e n existentes, pelo PCP um vértice se repete, e ele faz nosso processo de prev[] entrar em loop, isso significa que agora esse prev depois de n operações está em um ciclo. Logo, basta ficar retornando ele até achar ele denovo, e achamos um ciclo. 
		*/
		cout << "YES\n";
		for(int i = 0; i < n; i++){
			node = prv[node];
		}
		pathway.push_back(node);
		while(prv[node] != pathway[0]){
			pathway.push_back(prv[node]);
			node = prv[node];
		}
		pathway.push_back(prv[node]);
		for(int i = pathway.size()-1; i > 0; i--){
			cout << pathway[i] << " "; 
		}
		cout << pathway[0] << "\n";
	}
 
	return 0;
}