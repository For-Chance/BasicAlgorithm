#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return (b == 0) ? abs(a) : gcd(b, a % b);
}
ll n = 1001733993063167141;
ll d = 212353;
ll C = 20190324;
ll p = 891234941, q = 1123984201, e = 8.23816093931522e+17;

//ll n = 55;
//ll d = 3;
//ll C = 24;
//ll p = 5, q = 11, e;

int main(){
//	p = 2;
//	while(n != p * q){
//		if(n % p == 0){
//			q = n / p;
//			break;
//		}
//		p++;
//	}
//	ll X = 1;
//	ll pq = (p - 1) * (q - 1);
//	while((pq * X + 1) % d != 0){
//		X++;
//	}
//	e = (pq * X + 1) / d;
//	cout<<p<<" "<<q<<endl;
	cout<<e;
	return 0;
}

// 7.372527069113728e+16
