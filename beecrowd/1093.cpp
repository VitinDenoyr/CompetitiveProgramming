#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define pff pair<frac,frac>

ll mdc(ll a, ll b){
	if(a == 0) return b;
	return mdc(b%a,a);
}

struct frac {
	ll a, b;
	frac(ll _a, ll _b){
		a = _a; b = _b;
	}
	frac normalize(){
		ll m = mdc(a,b);
		return frac(a/m,b/m);
	}
	frac operator+(frac other){
		return frac((a*other.b + b*other.a),(other.b*b)).normalize();
	}
	frac operator-(frac other){
		return frac((a*other.b - b*other.a),(other.b*b)).normalize();
	}
	frac operator*(ll v){
		return frac(a*v,b);
	}
	frac operator*(frac other){
		return frac(a*other.a,b*other.b).normalize();
	}
	frac operator/(frac other){
		return frac(a*other.b,b*other.a).normalize();
	}
	frac operator^(ll expo){
		if(expo == 0) return frac(1,1);
		frac res (1,1);
		for(int _i = 1; _i <= expo; _i++){
			res = (res * frac(a,b)).normalize();
		}
		return res;
	}
	frac operator--(){
		return frac(b-a,b).normalize();
	}
	double dec(double mult = 1){
		normalize();
		return (((double)(a) * mult) / (double)(b));
	}
};

void solve(ll v1, ll v2, ll prop, ll d){
	v1 = (v1+d-1)/d;
	v2 = (v2+d-1)/d;
	frac pr (prop,6-prop);
	if(prop == 3){
		cout << (--frac(v2,v1+v2)).dec(100) << "\n";
	} else {
		frac num = (pr^(v2)) - frac(1,1);
		frac den = (pr^(v1+v2)) - frac(1,1);
		frac res = num/den;
		cout << (--res).dec(100) << "\n";
	}

}

int main(){

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int a,b,c,d; cin >> a >> b >> c >> d;
	cout << fixed << setprecision(1);
	while(!((a==0)&&(b==0)&&(c==0)&&(d==0))){
		solve(a,b,c,d);
		cin >> a >> b >> c >> d;
	}
	return 0;

}