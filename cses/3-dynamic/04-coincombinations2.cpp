#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000010
#define mod 1000000007
int m[MAXN], soma[MAXN];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n,s;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> m[i];
	}
	soma[0] = 1;
	for(int c = 0; c < n; c++){
		for(int i = 1; i <= s; i++){
			if(i < m[c]) continue; //Não da pra fazer essa soma colocando uma moeda desse valor
			soma[i] += soma[i - m[c]]; //Consigo fazer essa soma colocando essa moeda em uma qtd de vezes
			soma[i] %= mod;
		}
	}
	cout << soma[s] << "\n";

	return 0;
}