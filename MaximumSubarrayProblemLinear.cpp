// a linear time algorithm that solves the maximum subarray problem. 
#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 

int main(){
	int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}; 
	int dp[16]; 
	dp[0] = a[0];  
	for (int i = 1; i < 16; i++){
		dp[i] = max(0,dp[i-1]+a[i]);  
	}
	int ans; 
	for (int i = 0; i < 16; i++){
		ans = max(ans,dp[i]); 
	}
	cout << ans << endl; 
	return 0; 
}
