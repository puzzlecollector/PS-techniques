#include <iostream> 
#include <cstdio> 
#include <algorithm> 
using namespace std;  

int dp[MAXN+1][MAXW+1]; 
int v[MAXN],w[MAXN];  
int n,W;  

int main(){
  // assume we got some input here.  
  for (int i = 0; i <= W; i++){
    dp[0][i] = 0;  
  }
  for (int i = 1; i <= n; i++){
    for (int j = 0; j <= W; j++){
      if (j < w[i]){
        dp[i][j] = dp[i-1][j];  
      }else{
        dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);  
      }
    }
  }
  printf("%d\n",dp[n][W]);  
  return 0; 
} 
