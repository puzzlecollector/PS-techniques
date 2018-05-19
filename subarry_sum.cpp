/**** find the number of subarray that sums to k ****/ 
int a[MAXN]; 
map<int,int> mp; 
mp[0] = 1; 
int sum = 0, ans = 0; 
for (int i = 1; i <= n; i++){
	sum += a[i]; 
	ans += mp[sum-k]; 
	mp[sum]++; 
}
return ans; 
