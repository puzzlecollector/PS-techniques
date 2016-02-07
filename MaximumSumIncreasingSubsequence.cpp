// O(n^2) dynamic programming algorithm. 
// By Luke Minsuk Kim 
// This is just a slight modification of the LIS problem. 
#include <iostream>
#include <cstdio> 
#include <algorithm> 
using namespace std; 

int a[1001]; 
int dp[1001]; 

int main(){
	int n; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);  
	}
	int res = 0; 
	for (int i = 0; i < n; i++){
		dp[i] = a[i]; 
		for (int j = 0; j < i; j++){
			if (a[i] > a[j]){
				dp[i] = max(dp[i],dp[j]+a[i]); 
			}
		}
		res = max(res,dp[i]);  
	}
	printf("%d\n",res); 
	return 0; 	
}
