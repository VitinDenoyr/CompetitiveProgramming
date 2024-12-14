#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000006
 
struct fenwick {
    fenwick(int n){
        len = n;
        p = vector<int> (len,0);
    }
    vector<int> p; int len;
    void update(int ind, int inc){ //incrementa inc no indice ind
        if(ind == 0) p[0] += inc;
        while(ind > 0 && ind < len){
            p[ind] += inc;
            ind += ind&(-ind);
        }
    }
    int query(int i1, int i2){ //Soma de i1 a i2
        if(i1 == 0){
            int resp = 0;
            while(i2 > 0){
                resp += p[i2];
                i2 -= i2&(-i2);
            }
            return (resp + p[0]);
        }
        return query(0,i2) - query(0,i1-1);
    }
};
 
bool comp(vector<int> va, vector<int> vb){ //Ordem crescente de início e decrescente de final
	if(va[0] < vb[0]) return true;
	if(va[0] > vb[0]) return false;
	if(va[1] > vb[1]) return true;
	return false;
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
 
	int menorApos[n] = {0}, maiorAntes[n] = {0};
    int pos[n] = {0}; //posição do i-ésimo cara originalmente na nova ordenação
    set<int> fin; //finais de conjunto que existem
	for(int i = 0; i < n; i++){
		pos[v[i][2]] = i;
        fin.insert(v[i][1]);
	}
    
    unordered_map<int,int> mp; //mp[i] -> o i-ésimo menor cara tem valor tal
    int ct = 0; //existem ct finais diferentes
    for(auto fn : fin){
        mp[fn] = ct++; 
    }
 
    fenwick ftree(ct), ftree2(ct);
    for(int i = 0; i < n; i++){
        maiorAntes[v[i][2]] = ftree.query(mp[v[i][1]],ct-1);
        ftree.update(mp[v[i][1]],1);
 
        menorApos[v[n-i-1][2]] = ftree2.query(0,mp[v[n-i-1][1]]);
        ftree2.update(mp[v[n-i-1][1]],1);
    }
	
	for(int i = 0; i < n-1; i++){
		cout << menorApos[i] << " ";
	}
    cout << menorApos[n-1] << "\n";
	for(int i = 0; i < n-1; i++){
		cout << maiorAntes[i] << " ";
	}
    cout << maiorAntes[n-1] << "\n";
 
	return 0;
}