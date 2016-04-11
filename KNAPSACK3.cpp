// knapsack problem with large W 
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std;  

// dp[i+1][j] = when we chose up to i objects whose sum of values is j, dp[i+1][j] contains the minimum value of weight 

int dp[MAX_N+1][MAX_N*MAX_V+1]; 
void solve(){
  fill(dp[0],dp[0]+MAX_N*MAX_V+1,INF); 
  dp[0][0] = 0; 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < MAX_N*MAX_V; j++){
      if (j < v[i]){
        dp[i+1][j] = dp[i][j]; 
      }else{
        dp[i+1][j] = min(dp[i][j],dp[i][j-v[i]]+w[i]);
      }
    }
  }
  int res = 0; 
  for (int i = 0; i <= MAX_N*MAX_V; i++){
    if (dp[n][i] <= W) res = i;  
  }
  printf("%d\n",res); 
  return 0; 
} 
