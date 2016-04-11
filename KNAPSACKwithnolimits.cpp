#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

#define MAXN 101 
#define MAXW 10001 

int dp[MAXN][MAXW];  
int v[MAXN],w[MAXN];  
int n,W;  

int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> w[i] >> v[i];  
	}
	cin >> W; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j <= W; j++){
			if (j < w[i]){
				dp[i+1][j] = dp[i][j];  
			}else{
				dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]]+v[i]);  
			}
		}
	}
	cout << dp[n][W] << endl; 
	return 0; 
}
