#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
 
    int n; ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while(cin >> n && n != 0){
		map<ll,int> m;
        for(int i = 0; i < n; i++){
            ll k;
            cin >> k;
			m[k]++;
        }
		int espacinho = 0;
		for(auto it : m){
			if(it.second%2 == 1){
				cout << it.first;
				if(espacinho%2 == 0){
					cout << " ";
					espacinho++;
				} else {
					cout << "\n";
					break;
				}
			}
		}
    }
 
    return 0;
}