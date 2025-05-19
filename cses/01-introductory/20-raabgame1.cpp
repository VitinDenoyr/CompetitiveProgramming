#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int t; cin >> t;
	while (t--){
		int n,a,b; cin >> n >> a >> b;
		if(a + b > n || (min(a,b) == 0 && max(a,b) != 0)){
			cout << "NO\n";
		} else {
			if(a == b && b == 0){
				cout << "YES\n";
				for(int i = 1; i <= n; i++){
					cout << i << " \n"[i==n];
				}
				for(int i = 1; i <= n; i++){
					cout << i << " \n"[i==n];
				}
			} else if(min(a,b) == 1){
				cout << "YES\n";
				if(b == 1){
					for(int i = 1; i <= n; i++){
						cout << n+1-i << " \n"[i==n];
					}
					for(int i = 1; i <= a; i++){
						cout << n-i << " ";
					}
					cout << n << " \n"[a == (n-1)];
					for(int i = a+2; i <= n; i++){
						cout << n+1-i << " \n"[i==n];
					}
				} else {
					for(int i = 1; i <= b; i++){
						cout << n-i << " ";
					}
					cout << n << " \n"[b == (n-1)];
					for(int i = b+2; i <= n; i++){
						cout << n+1-i << " \n"[i==n];
					}
					for(int i = 1; i <= n; i++){
						cout << n+1-i << " \n"[i==n];
					}
				}
			} else {
				cout << "YES\n";
				for(int i = 1; i <= n; i++){
					cout << n+1-i << " \n"[i==n];
				}
				for(int i = 1; i <= a; i++){
					cout << n+1-i-b << " \n"[i==n];
				}
				for(int i = 1; i <= b; i++){
					cout << n+1-i << " \n"[(i+a)==n];
				}
				for(int i = a+b+1; i <= n; i++){
					cout << n+1-i << " \n"[i==n];
				}
			}
			
		}
	}
	return 0;

}