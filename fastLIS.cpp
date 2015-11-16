/*
Another way of solving the LIS problem: https://algospot.com/judge/problem/read/LIS
This algorithm takes O(nlgn) time complexity to find the length of the longest increasing
subsequence. Let dp[i] = the minimum value of the last element of a LIS of length i+1. 

설명: 최초 dp[i]의 값을 모두 INF라고 합시다. 배열의 요소를 이전부터 순서대로 봐가면서 
각 a_j에 대해서 i=0또는 dp[i-1] < a_i라면 dp[i] = min(dp[i],a_j)로 갱신됩니다. 
마지막으로 dp[i] < INF가 되는 i+1이 정답.  
*/

#include <iostream>
#include <algorithm>
#include <cstring> 
#include <cstdlib>
using namespace std; 

#define MAXN 500 
#define INF 1e9	

int c,n; 
int dp[MAXN]; 
int a[MAXN];  

void solve(){
	fill(dp,dp+n,INF); 
	for (int i = 0; i < n; i++){
		*lower_bound(dp,dp+n,a[i]) = a[i];  
	}
	int ans = lower_bound(dp,dp+n,INF)-dp; 
	cout << ans << endl;
}

int main(){
	cin >> c; 
	for (int i = 0; i < c; i++){
		cin >> n; 
		for (int j = 0; j < n; j++){
			cin >> a[j]; 
		}
		solve(); 
	}
	return 0; 
}
