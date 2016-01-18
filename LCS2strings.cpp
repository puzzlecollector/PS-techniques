// Problem Link: https://www.acmicpc.net/problem/9252
// Iterative DP approach to solving the Longest Common Subsequence Problem (of 2 strings). 
// Time complexity is O(mn). 
#include <iostream> 
#include <string> 
#include <algorithm> 
using namespace std; 

int m,n;  
int lcs[1001][1001];  

int Len(string s1,string s2){
	for (int i = m; i >= 0; i--){
		for (int j = n; j >= 0; j--){
			if (i == m || j == n){
				lcs[i][j] = 0; 
			}else if (s1[i] == s2[j]){
				lcs[i][j] = 1+lcs[i+1][j+1];  
			}else{
				lcs[i][j] = max(lcs[i+1][j],lcs[i][j+1]);  
			}
		}
	}
	return lcs[0][0];  
}

string actual(string s1, string s2){
	string t = "";  
	int i = 0, j = 0;  
	while (i < m && j < n){
		if (s1[i] == s2[j]){
			t += s1[i]; 
			i++, j++;  
		}else if (lcs[i+1][j] >= lcs[i][j+1]){
			i++; 
		}else{
			j++; 
		}
	}
	return t; 
}

int main(){
	string s1,s2; 
	cin >> s1 >> s2; 
	m = (int)s1.size();  
	n = (int)s2.size();  
	int ans = Len(s1,s2); 
	string actualLCS = actual(s1,s2); 
	cout << ans << endl; 
	cout << actualLCS << endl; 
	return 0; 
}	
