#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define a0 {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

struct Trie {
	vector<array<int,26>> adj;
	vector<int> qt; bool suffix = false;
	Trie(bool suffixTrie = false){
		qt.push_back(0);
		adj.push_back({a0});
		suffix = suffixTrie;
	}
	void add(string s){
		int i = 0, c = 0;
		while(c < s.size()){
			if(!adj[i][(suffix ? (s[s.size()-1-c]-'a') : (s[c]-'a'))]){
				adj[i][(suffix ? (s[s.size()-1-c]-'a') : (s[c]-'a'))] = qt.size();
				qt.push_back(0);
				adj.push_back(a0);
			}
			i = adj[i][(suffix ? (s[s.size()-1-c]-'a') : (s[c]-'a'))]; qt[i]++;
			c++;
		}
	}
	ll get(string s){
		ll res = 0; int i = 0, c = 0;
		while(c < s.size()){
			if(!adj[i][(suffix ? (s[s.size()-1-c]-'a') : (s[c]-'a'))]){
				return res;
			}
			i = adj[i][(suffix ? (s[s.size()-1-c]-'a') : (s[c]-'a'))]; 
			res += (ll)qt[i];
			c++;
		}
		return res;
	}
};

void solve(){

	int n; cin >> n;
	vector<string> s (n+1, "");
	Trie pre;

	for(int i = 1; i <= n; i++){
		cin >> s[i];
		pre.add(s[i]);
	}

	ll resp = 0;
	for(int i = 1; i <= n; i++){
		reverse(s[i].begin(),s[i].end());
		resp += 2*n*s[i].size() - 2*pre.get(s[i]);
	}

	cout << resp << "\n";
}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	solve();
	return 0;

}