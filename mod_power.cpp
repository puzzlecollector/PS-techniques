typedef long long ll;  
ll mod_pow(int a, int x, int mod){
	if (x == 0) return 1%mod; 
	ll res = mod_pow(a,x/2,mod);  
	if (x%2 == 0) return (res*res)%mod; 
	return (a*((res*res)%mod))%mod; 
}
