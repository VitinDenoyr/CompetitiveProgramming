#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){
	//Leitura de N e dos pesos
	int n; cin >> n;
	vector<int> weight (n+1, 0);
	vector<pii> vec;
	for(int i = 1; i <= n; i++){
		cin >> weight[i];
		vec.push_back({weight[i],i});
	}

	//Leitura das arestas
	vector<vector<int>> adj (n+1, vector<int>());
	for(int i = 1; i < n; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	//Enraização da árvore em 1
	vector<vector<int>> parent (n+1, vector<int>(21, 0));
	vector<int> lvl (n+1, -1);
	parent[1][0] = -1; lvl[1] = 0;
	function<void(int)> root = [&](int a){
		for(int u : adj[a]){
			if(!parent[u][0]){ 
				parent[u][0] = a;
				lvl[u] = lvl[a]+1;
				root(u);
			}
		}
	};
	root(1);
	parent[1][0] = 0;

	//Ordenação dos nós por valor maior
	function<bool(pii,pii)> comp = [&](pii a, pii b){
		return (a.first > b.first);
	};
	sort(vec.begin(),vec.end(),comp);

	//Calcula ao avanço rápido de um nó em potências de 2
	for(int j = 1; j <= 20; j++){
		for(int i = 1; i <= n; i++){
			if(parent[i][j-1] <= 0){
				parent[i][j] = 0;
			} else {
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}

	//Faz a função que calcula o LCA de dois nós
	function<int(int,int)> lca = [&](int a, int b){
		//Garante que a é o maior
		if(lvl[a] < lvl[b]) swap(a,b);
		int lvlDif = lvl[a] - lvl[b];

		//Sobe o a até ter o mesmo nível de b
		for(int j = 20; j >= 0; j--){
			if(lvlDif & (1<<j)){
				a = parent[a][j];
			}
		}

		//Se já forem iguais, retorna
		if(a == b) return a;

		//Agora faz o binary lifting
		for(int j = 20; j >= 0; j--){
			if(parent[a][j] != parent[b][j]){
				a = parent[a][j];
				b = parent[b][j];
			}
		}

		//O pai deles é o LCA
		return parent[a][0];
	};

	//Diz que todos os nós maiores já não podem ser escolhidos e guarda o LCA deles
	int k = 1, bigLca = vec[0].second, equalLca = 0;
	while(vec[k].first == vec[0].first){
		bigLca = lca(bigLca, vec[k].second);
		k++;
		if(k == vec.size()) break;
	}

	for(int i = k; i < vec.size(); i++){
		//Se esse valor for diferente do anterior, implica que o antecessor de todos que são maiores é o bigLca
		if(vec[i].first < vec[i-1].first && equalLca != 0){
			bigLca = lca(bigLca, equalLca);
			equalLca = 0;
		}

		//Se esse número menor remover todos os maiores, então escolher ele é derrota imediata
		int newLca = lca(bigLca, vec[i].second);
		if(lvl[vec[i].second] <= lvl[bigLca] && newLca == vec[i].second){
			if(equalLca == 0){
				equalLca = vec[i].second;
			} else {
				equalLca = lca(equalLca, vec[i].second);
			}
		}
		//Mas se não for derrota imediata, implica que podemos remover esse nó e deixar o oponente só com nós de derrota imediata, que são os maiores que esse. Então, esse nó pode ser escolhido para a vitória
		else {
			cout << vec[i].second << "\n";
			return;
		}
	}

	//Se chegamos até aqui, indica que todos são de derrota imediata
	cout << 0 << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while(t--){
		solve();
	}

	return 0;
}