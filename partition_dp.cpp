#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
using namespace std; 
int cache[101][101];  
int solve(int n,int k){
	if (k == 0 || n == 0) return 0;  
	if (k == 1 || k == n) return 1; 
	int &ret = cache[n][k]; 
	if (ret != -1) return ret; 
	ret = 0; 
	if (n >= 1 && k >= 1) ret += solve(n-1,k-1);  
	if (n >= k) ret += solve(n-k,k); 
	return ret;  
}
int main(){
	int n,m; 
	cin >> n >> m; 
	memset(cache,-1,sizeof(cache)); 
	cout << solve(n,m) << endl; 
	return 0; 
}
