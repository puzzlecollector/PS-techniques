#include <iostream>
#include <cstdlib>
using namespace std; 
int n,m; 
int dp[101][101]; 
void solve(){
	dp[0][0] = 1; 
	for (int i = 1; i <= m; i++){
		for (int j = 0; j <= n; j++){
			if (j-i >= 0){
				dp[i][j] = dp[i-1][j]+dp[i][j-i]; 
			}else{
				dp[i][j] = dp[i-1][j]; 
			}
		}
	}
	cout << dp[m][n] << endl; 
}
int main(){
	cin >> n >> m;  
	solve();  
	return 0;  
}
