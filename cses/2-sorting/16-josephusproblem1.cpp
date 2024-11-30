#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,k = 1;

int mod(int a, int b){
	return (a%b)+b*(a%b==0);
}

void vivo(int m){
	vector<vector<int>> v;
	vector<int> ev;
	int sq = sqrt(m);
	for(int i = 0; i < m; i++){
		if(i%sq == 0) v.push_back(ev);
		v[i/sq].push_back(i+1);
	}

	int atl = 0, atc = 0;
	for(int i = 0; i < m; i++){
		int add;
		add = (k)%(m-i);
		while(atc+add >= v[atl].size()){
			add -= v[atl].size();
			atl = (atl+1)%(v.size());
		}
		atc += add;
		cout << v[atl][atc] << " ";
		v[atl].erase(v[atl].begin() + atc);
	}
	
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;

    vivo(n);

    return 0;
}