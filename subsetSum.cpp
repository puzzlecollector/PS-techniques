#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
using namespace std; 

int a[MAXN];  
int n,k; 

bool dfs(int i, int sum){
  if (i == n) return sum == k;  
  if (dfs(i+1,sum)) return true; 
  if (dfs(i+1,sum+a[i])) return true;  
  return false; 
} 

void solve(){
  if (dfs(0,0)) printf("YES\n");  
  else printf("NO\n");  
} 

int main(){
  // input
  solve(); 
  return 0; 
} 
