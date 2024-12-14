#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n,k; cin >> n;
	stack<pii> s;
	for(int i = 0; i < n; i++){
		cin >> k;
		while(s.size() > 0){
			if(k > s.top().first){
				cout << s.top().second << " ";
				s.push({k,i+1});
				break;
			} else {
				s.pop();
			}
		}
		if(s.size() == 0){
			cout << 0 << " ";
			s.push({k,i+1});
		}
	}

	return 0;
}