#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define INF 1000000011
ll maxval[2*MAXN] = {0};

struct Fenwick { //guarda o maior dinheiros de um cara q termina em alguem daquele intervalo
    vector<ll> v; int len;
    Fenwick(int l){
        len = l;
        v = vector<ll> (len, 0);
    }
    void update(int ind, ll va){ //um cara com essa quantidade de dinheirus termina em ind
        while(ind < len){
            if(v[ind] < va) v[ind] = va;
            ind += (ind&(-ind));
        }
    }
    ll query(int b){ //qual maior quantidade de money q consigo se terminar em até b
        ll resp = 0;
        while(b > 0){
            if(resp < v[b]) resp = v[b];
            b -= (b&(-b));
        }
        return resp;
    }
};

int main(){

	int n, s0, e0, v0;
	vector<pair<int,int>> e, start;
	vector<int> s, val;
	cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s0 >> e0 >> v0;
        e.push_back({e0,i});
		s.push_back(s0); //unsorted start
		start.push_back({s0,i}); //sorted start
		val.push_back(v0);
    }
    start.push_back({INF,-1}), e.push_back({INF,-1});

	sort(start.begin(),start.end()); sort(e.begin(),e.end());
    int k = 0, iS = 0, iE = 0, ant = -1;
    while(iS < n || iE < n){
        if(start[iS].first <= e[iE].first){
            if(ant < start[iS++].first){
				ant = start[iS - 1].first;
				s[start[iS - 1].second] = ++k;
			} else {
				ant = start[iS - 1].first;
				s[start[iS - 1].second] = k;
			}
        } else {
			if(ant < e[iE++].first){
				ant = e[iE - 1].first;
				e[iE - 1].first = ++k;
			} else {
				ant = e[iE - 1].first;
				e[iE - 1].first = k;
			}
        }
    }
	e.pop_back(); start.clear();
	
	Fenwick ftree(k+1); ll truemaxval = 0;
	ftree.update(e[0].first,val[e[0].second]);
    maxval[e[0].first] = val[e[0].second];
    truemaxval = maxval[e[0].first];

	for(int i = 1; i < n; i++){
        ll m = ftree.query(s[e[i].second]-1);
        if(maxval[e[i].first] < m + val[e[i].second]) maxval[e[i].first] = m + val[e[i].second];
        truemaxval = max(truemaxval,maxval[e[i].first]);
        ftree.update(e[i].first,maxval[e[i].first]);
    }
	cout << truemaxval << "\n";

	return 0;
}