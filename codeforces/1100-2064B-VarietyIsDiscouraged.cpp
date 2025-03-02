//https://codeforces.com/problemset/problem/2064/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

void solve(){

	int n; cin >> n;
	vector<int> a (n+2, 0), uniq (n+2, 0);
	map<int,int> qt; int numsolo = 0;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
		qt[a[i]]++;
		if(qt[a[i]] == 1) numsolo++;
		if(qt[a[i]] == 2) numsolo--;
	}
	for(int i = 1; i <= n; i++){
		if(qt[a[i]] == 1) uniq[i] = 1;
	}
	if(numsolo == 0){ //melhor resposta é nem mexer, só da pra tirar repetido
		cout << 0 << "\n";
	} else { //Existe no mínimo algum número solo. Só preciso achar o maior subarray de solos
		int bl = n+1, br = -1, l = n+1;
		for(int i = 1; i <= n+1; i++){
			if(uniq[i] == 1){
				if(l == n+1) l = i;
			} else {
				int r = i-1;
				if(br - bl + 1 < r - l + 1){
					br = r; bl = l;
				}
				l = n+1;
			}
		}
		cout << bl << " " << br << "\n";
	}
}

int main(){

	int t; cin >> t;
	while (t--){
		solve();
	}
	return 0;

}