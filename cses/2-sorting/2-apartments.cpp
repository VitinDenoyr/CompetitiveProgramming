#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n,m,maxdif,el;
	cin >> n >> m >> maxdif;
	vector<int> v, ap;
	for(int i = 0; i < n; i++){
		cin >> el;
		v.push_back(el);
	}
	for(int i = 0; i < m; i++){
		cin >> el;
		ap.push_back(el);
	}
	sort(v.begin(), v.end());
	sort(ap.begin(),ap.end());
	int resp = 0, i = 0, j = 0;
	while(i < v.size() && j < ap.size()){
		if(abs(v[i] - ap[j]) <= maxdif){
			j++; i++; resp++;
		} else if(v[i] > ap[j]){
			j++;
		} else {
			i++;
		}
	}
	cout << resp << "\n";


	return 0;
}