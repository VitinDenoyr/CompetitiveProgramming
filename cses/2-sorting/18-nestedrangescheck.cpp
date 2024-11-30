#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000006

bool comp(vector<int> va, vector<int> vb){ //Ordem crescente de início e decrescente de final
	if(va[0] < vb[0]) return true;
	if(va[0] > vb[0]) return false;
	if(va[1] > vb[1]) return true;
	return false;
}

bool def(vector<int> va, vector<int> vb){
	return va[2] <= vb[2];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n,a,b;
	vector<vector<int>> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		v.push_back({a,b,i});
	}
	sort(v.begin(),v.end(),comp);
	int minApos[n+1] = {0}, maxAntes[n+1] = {0}, pos[n] = {0};
	int minim = INF, maxim = -INF;
	for(int i = 0; i < n-1; i++){
		maxim = max(maxim,v[i][1]);
		maxAntes[i+1] = maxim;
		minim = min(minim,v[n-1-i][1]);
		minApos[n-2-i] = minim;
		pos[v[i][2]] = i;
	}
	pos[v[n-1][2]] = n-1;
	maxAntes[0] = -INF; minApos[n-1] = INF;
	
	sort(v.begin(),v.end(),def);
	for(int i = 0; i < n; i++){
		if(v[i][1] >= minApos[pos[i]]){
			cout << 1;
		} else {
			cout << 0;
		}
		if(i == n-1){
			cout << "\n";
		} else {
			cout << " ";
		}
	}
	for(int i = 0; i < n; i++){
		if(v[i][1] <= maxAntes[pos[i]]){
			cout << 1;
		} else {
			cout << 0;
		}
		if(i == n-1){
			cout << "\n";
		} else {
			cout << " ";
		}
	}

	return 0;
}

//um conjunto começa antes de todos os caras depois dele
//pega o mínimo término depois dele, se esse cara for < termino dele, então existe quem é contido
//um conjunto começa depois de todos os caras antes dele
//pega o máximo término antes dele, se esse cara for > término dele, então existe quem contem