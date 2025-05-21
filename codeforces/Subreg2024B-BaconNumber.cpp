//https://codeforces.com/gym/105327/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int n,m;

int conv(int x){
	if(x > m) x -= m;
	return x;
}

int main(){

	cin >> n >> m;
	vector<vector<int>> adj (n+m+1, vector<int>());
	for(int i = 1; i <= n; i++){
		int ni; cin >> ni;
		for(int j = 1; j <= ni; j++){
			int x; cin >> x;
			adj[m+i].push_back(x);
			adj[x].push_back(m+i);
		}
	}

	vector<int> par (n+m+1, 0);
	function<void(int)> look = [&](int k){
		for(int u : adj[k]){
			if(!par[u]){
				par[u] = k;
				look(u);
			}
		}
	};

	for(int i = 1; i <= n+m; i++){
		if(!par[i]){
			par[i] = i;
			look(i);
		}
	}

	int q; cin >> q;
	vector<int> vis (n+m+1, 0);
	for(int iq = 1; iq <= q; iq++){
		int a,b; cin >> a >> b;
		int pa = a, pb = b;
		while(par[pa] != pa){
			vis[pa] = iq;
			pa = par[pa];
		}
		vis[pa] = iq;
		int rt = 0;
		while(par[pb] != pb){
			if(vis[pb] == iq){
				rt = pb;
				break;
			}
			pb = par[pb];
		}
		if(vis[pb] == iq){
			rt = pb;
		}

		if(rt == 0){
			cout << -1 << "\n";
		} else {
			std::stringstream r;
			int qtd = 1;
			r << conv(a);
			while(a != rt){
				a = par[a];
				r << " " << conv(a);
				qtd++;
			}
			stack<int> st;
			st.push(conv(b));
			while(b != rt){
				b = par[b];
				st.push(conv(b));
				qtd++;
			}
			st.pop();

			while(!st.empty()){
				r << " " << conv(st.top());
				st.pop();
			}
			cout << qtd - qtd/2 << "\n";
			cout << r.str() << "\n";
		}
	}

	return 0;

}