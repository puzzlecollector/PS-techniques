// knapsack 
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
using namespace std; 
int cache[100][100];  
int n;  
int W;  
int weight[100];  
int price[100];  
int knapsack(int i,int j){
	if (i == n) return 0;  
	int &ret = cache[i][j];  
	if (ret != -1) return ret;  
	ret = knapsack(i+1,j);  
	if (j >= weight[i]){
		ret = max(ret,knapsack(i+1,j-weight[i])+price[i]);  
	}
	return ret;  
}

int main(){
	memset(cache,-1,sizeof(cache));  
	cin >> n; 
	cin >> W; 
	for (int i = 0; i < n; i++){
		cin >> weight[i] >> price[i];  
	}
	int ans = knapsack(0,W); 
	cout << ans << endl; 
	return 0;  
}
