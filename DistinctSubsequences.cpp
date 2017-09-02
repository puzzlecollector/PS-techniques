// given S and T, find how many subsequences of S match T
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm> 
using namespace std; 
int count(string S,string T){	
	int m = T.size(), n = S.size();  
	if (m > n) return 0; 
	int dp[m+1][n+1]; // dp[T][S]
	for (int i = 0; i <= m; i++){
		dp[i][0] = 0; // if S is empty, there are no subsequences of S that match T
	}
	for (int i = 0; i <= n; i++){
		dp[0][i] = 1; // if T is empty there is only one subsequence of S that matches T
	}
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (T[i-1] != S[j-1]){
				dp[i][j] = dp[i][j-1]; 
			}else{
				dp[i][j] = dp[i][j-1]+dp[i-1][j-1];  
			}
		}
	}
	return dp[m][n];  
}
int main(){
	string S,T; 
	cin >> S >> T; 
	cout << count(S,T) << endl; 
	return 0; 
}
