#include <cstdio> 
#include <climits>
#include <algorithm> 
using namespace std; 

int a[100001]; 
int dp[100001];  

int main(){
	int n; 
	scanf("%d",&n); 
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]); 
	}
	int res = INT_MIN;  
	dp[0] = a[0];  
	res = max(res,dp[0]); 
	for (int i = 1; i < n; i++){
		dp[i] = max(a[i],dp[i-1]+a[i]);  
		res = max(res,dp[i]); 
	}
	printf("%d\n",res);  
	return 0; 
}
