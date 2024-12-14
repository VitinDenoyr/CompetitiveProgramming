#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		ll u,v;
		cin >> u >> v;
		ll key = max(u,v), resp;
		if(key%2 == 1){
			if(key == u){
				resp = (u-1)*(u-1) + v;
			} else {
				resp = v*v - (u-1);
			}
		} else {
			if(key == v){
				resp = (v-1)*(v-1) + u;
			} else {
				resp = u*u - (v-1);
			}
		}
		cout << resp << "\n";
	}

	return 0;
}