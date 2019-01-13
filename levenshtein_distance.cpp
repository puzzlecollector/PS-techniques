#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int minf(int a,int b,int c){
	return min(a,min(b,c));  
}
int dp[1001][1001]; 
int ptr[1001][1001]; 
int main(){
	string s,t; 
	cin >> s >> t; // transform s to t 
	int n = s.size(), m = t.size();  
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if (i == 0) dp[i][j] = j; 
			else if (j == 0) dp[i][j] = i;  
			else if (s[i-1] == t[j-1]){
				dp[i][j] = dp[i-1][j-1];  
			}else{
				dp[i][j] = minf(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+2);
			}
		}
	}	
	cout << dp[n][m] << endl; 
	cout << "dp table" << endl; 
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			cout << dp[i][j] << " "; 
		}
		cout << endl; 
	}
	return 0; 
}
