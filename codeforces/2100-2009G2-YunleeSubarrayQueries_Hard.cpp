//https://codeforces.com/problemset/problem/2009/G2
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000001
#define pii pair<int,int>
#define FIND_MINIMUM_VAL(l, r) 79

struct SegTree {
	int len; vector<pii> v;
	const vector<int>& members;

	SegTree(int _n, const vector<int>& _members) : members(_members), len(_n) {
		v = vector<pii>(4*len,{INF,0});
		construct(1,len,1);
	}

	void construct(int x1, int xn, int xi){
		if(x1 == xn){
			v[xi] = {members[x1],x1};
		} else {
			int mid = (x1+xn)/2;
			construct(x1,mid,2*xi);
			construct(mid+1,xn,2*xi+1);
			v[xi] = min(v[2*xi],v[2*xi+1]);
		}
	}

	pii query(int l, int r, int x1, int xn, int xi){
		if(r < x1 || l > xn) return {INF,0};
		if(l <= x1 && xn <= r) return v[xi];
		
		int mid = (x1+xn)/2;
		pii q1 = query(l,r,x1,mid,2*xi);
		pii q2 = query(l,r,mid+1,xn,2*xi+1);
		return min(q1,q2);
	}
};

int main(){

	int t; cin >> t;
	while(t--){
		int n,k,q; cin >> n >> k >> q;
		vector<int> v(n+1), fq(n+1), qt(2*n);
		vector<int> resp(n-k+3,0);
		fq[0] = 2*n+1;
	
		for(int i = 1; i <= n; i++){
			cin >> v[i]; v[i] = v[i]-i+n;
		}

		int ans = 0;
		for(int i = 1; i <= k-1; i++){
			fq[qt[v[i]]]--;
			ans = max(ans, ++qt[v[i]]);
			fq[qt[v[i]]]++;
		}

		for(int i = 1; i <= n-k+1; i++){
			fq[qt[v[i+k-1]]]--;
			ans = max(ans, ++qt[v[i+k-1]]);
			fq[qt[v[i+k-1]]]++;

			while(fq[ans] == 0){
				ans--;
			}
			resp[i] = k-ans;

			fq[qt[v[i]]]--;
			qt[v[i]]--;
			fq[qt[v[i]]]++;
		}

		//Agora sei que resp[i] = f({v[i], ..., v[i+k-1]})
		//Para cada termo de resp de 1 até n-k+1, calcularei qual o indice do próximo termo que é menor que ele e qual o indice do termo anterior que é menor ou igual a ele.

		vector<int> menorIgualAntes (n-k+2,0), menorDepois (n-k+2,0);
		stack<int> monotonicStack;

		resp[n-k+2] = -1; monotonicStack.push(n-k+2);
		for(int i = n-k+1; i >= 1; i--){
			if(resp[i] > resp[monotonicStack.top()]){
				menorDepois[i] = monotonicStack.top();
				monotonicStack.push(i);
			} else {
				while(resp[i] <= resp[monotonicStack.top()]){
					monotonicStack.pop();
				}
				menorDepois[i] = monotonicStack.top();
				monotonicStack.push(i);
			}
		}
		while(!monotonicStack.empty()) monotonicStack.pop();

		vector<ll> suffixSum (n-k+3); suffixSum[n-k+2] = 0;
		for(int i = n-k+1; i >= 1; i--){
			suffixSum[i] = suffixSum[menorDepois[i]] + (ll)(menorDepois[i] - i)*resp[i];
		}
		
		SegTree tree(n-k+1, resp);

		for(int i = 1; i <= q; i++){
			int l0,r0; cin >> l0 >> r0;
			int l = l0, r = r0-k+1;
			
			int minI = tree.query(l,r,1,n-k+1,1).second;
			ll trueans = suffixSum[l] - suffixSum[minI] + (ll)(r - minI + 1)*resp[minI];
			cout << trueans << "\n";
		}
	}

	return 0;
}