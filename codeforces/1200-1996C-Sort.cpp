//https://codeforces.com/contest/1996/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define printvec(vtr) for(auto k : vtr){cout << k << ' ';}; cout << endl

int main(){

	int t; cin >> t;
	for(int it = 0; it < t; it++){
		int n,q; cin >> n >> q;
		int qta[26][n+1] = {0};
		int qtb[26][n+1] = {0};
		string a,b;
		cin >> a >> b;
		for(int ic = 1; ic <= n; ic++){
			for(int cc = 0; cc < 26; cc++){
				qta[cc][ic] = qta[cc][ic-1] + ((a[ic-1]-'a') == cc);
				qtb[cc][ic] = qtb[cc][ic-1] + ((b[ic-1]-'a') == cc); 
			}
		}
		int l,r;
		for(int i = 0; i < q; i++){
			cin >> l >> r;
			int resp = (r-l+1);
			for(int cc = 0; cc < 26; cc++){
				int iqa = qta[cc][r] - qta[cc][l-1];
				int iqb = qtb[cc][r] - qtb[cc][l-1];
				resp -= min(iqa,iqb);
			}
			cout << resp << "\n";
		}
	}

	return 0;
}