ll fastexpo(ll a, ll x, ll mod){
	ll res = 1;  
	while (x){
		if (x&1) res = res*a%mod; 
		a = a*a%mod;  
		x >>= 1;  
	}
	return res; 
}
