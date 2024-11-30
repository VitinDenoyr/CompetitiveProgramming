//https://codeforces.com/contest/839/problem/D
#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define MAXV 1000005
#define mod 1000000007
#define ll long long
#define printvec(vc,k) for(int zi = 0; zi < k; zi++){cout << vc[zi] << ' ';}; cout << endl
int v[MAXN] = {0}, mult[MAXV] = {0};
ll mdcClan[MAXV];
ll pwr[MAXV] = {1,2,4,8,16,32,64};
ll chooses[MAXN] = {0};

ll twopow(int exp){
	if(pwr[exp] > 0) return pwr[exp];
	pwr[exp] = (2*twopow(exp-1))%mod;
	return pwr[exp];
}

ll calcChooses(int qt){
	if(qt == 0) return 0;
	if(chooses[qt] != 0) return chooses[qt];
	chooses[qt] = ((calcChooses(qt-1)*2)%mod + twopow(qt-1))%mod;
	return chooses[qt];
}

int main(){
	int n, gtr=0, gtrMult = 0; cin >> n;
	for(int i = 0; i < n; i++){
		cin >> v[i]; gtr = max(gtr,v[i]);
		for(int k = 1; k*k <= v[i]; k++){
			if(v[i]%k == 0){
				mult[k]++;
				gtrMult = max(gtrMult, mult[k]);
				if(k*k != v[i]){
					mult[v[i]/k]++;
					gtrMult = max(gtrMult, mult[v[i]/k]);
				}
			}
		}
	}
	ll resp = 0; twopow(gtrMult);
	for(int i = gtr; i > 1; i--){ //Veremos os clans com mdcClan i
		mdcClan[i] = calcChooses(mult[i]); //combinacoes possiveis com todos os multiplos de i
		for(int ret = 2*i; ret <= gtr; ret += i){ //tira os clans entre multiplos de k*i, k > 1
			mdcClan[i] = (mdcClan[i] - mdcClan[ret] + mod)%mod;
		}
		resp = (resp + mdcClan[i]*i)%mod;
	}
	cout << resp << "\n";

	return 0;
}


// 1 -> 1 = 1
// 2 -> 1+1+2 = 4
// 3 -> 4+4+4 = 12
// 4 -> 12+12+8 = 32