#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;  
int dp[100005]; 
int val[1005],wt[1005]; 
int main(){
	int N,W; 
	cin >> N >> W;  
	for (int i = 0; i < N; i++){
		cin >> val[i];  
	}
	for (int i = 0; i < N; i++){
		cin >> wt[i]; 
	}
	for (int i = 0; i <= W; i++){
		for (int j = 0; j < N; j++){
			if (wt[j] <= i) dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);  
		}
	}
	cout << dp[W] << endl; 
	return 0; 
}
