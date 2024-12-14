#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
 
int main(){
    
    int n, s; cin >> n >> s;
    vector<pii> v (n, {0,0});
    for(int i = 0; i < n; i++){
		int k; cin >> k;
		v[i] = {k, i+1};
    }
    sort(v.begin(),v.end());

	int l = 0, r = n-1;
	while(true){ //Repita o processo
		if(v[l].first + v[r].first == s && l != r){ //Encontramos a soma
			cout << v[l].second << " " << v[r].second << "\n";
			return 0; 
		} else if(v[l].first + v[r].first < s){ //Precisamos aumentar a soma
			l++;
		} else { //Precisamos diminuir
			r--;
		}

		if(l >= r){
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
 
    return 0;
}
