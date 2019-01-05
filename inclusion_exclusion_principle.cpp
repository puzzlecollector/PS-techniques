#include <iostream>
#include <algorithm>
using namespace std; 
typedef long long ll; 
int a[16]; 
int N,K;  
ll gcd(ll x,ll y){
	if (y == 0) return x; 
	return gcd(y,x%y); 
}
void solve(){
	cin >> N >> K; 
	for (int i = 0; i < K; i++){
		cin >> a[i]; 
	}
	ll res = 0; 
	for (int i = 1; i < (1<<K); i++){
		int num = 0;  
		for (int j = i; j != 0; j >>= 1){
			num += j&1; // how many on bits in i
		}
		ll lcm = 1LL;  
		for (int j = 0; j < K; j++){
			if (i >> j & 1){
				lcm = lcm/gcd(lcm,a[j]) * a[j]; 
				if (lcm > N) break; 
			}
		}
		if (num&1) res += N/lcm;  // odd 
		else res -= N/lcm; 
	}
	cout << N-res << "\n"; 
}
int main(){
	solve(); 
	return 0; 
}
