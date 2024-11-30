#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){

	int n,k,resp=0; cin >> n;
	int m[n], sum[n] = {0}; //moedas de 1 a n, soma das primeiras moedas até i
	for(int i = 0; i < n; i++){
		cin >> m[i];
		sum[i] = m[i];
		if(i > 0) sum[i] += sum[i-1];
	}
	int qt[sum[n-1]+1] = {1}; //quantidade de formas de fazer a soma i. soma 0 -> 1 jeito
	for(int i = 0; i < n; i++){
		for(int j = sum[i]; j >= m[i]; j--){
			int prev = qt[j];
			qt[j] += qt[j-m[i]];
			if(!prev && qt[j]) resp++;
		}
	}
	cout << resp << "\n";
	for(int i = 1; i <= sum[n-1]; i++){
		if(qt[i]) cout << i << " ";
	}
	cout << "\n";

	return 0;
}