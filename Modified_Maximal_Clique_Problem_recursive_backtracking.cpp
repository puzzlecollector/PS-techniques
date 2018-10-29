// is the size of the maximal clique at least K?  
#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <vector> 
using namespace std; 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
int grid[909][909]; 
int K,N,F; 
vector<int> ans;  
bool dfs(int x,vector<int> v){
	bool ret = false; 
	if (v.size() >= K){
		ans = v; 
		return true;
	}
	if (ret){
		ans = v; 
		return ret; 
	}
	for (int i = 1; i <= N; i++){
		bool cannot_join = false;  
		for (int j = 0; j < v.size(); j++){
			if (grid[i][v[j]] == 0){
				cannot_join = true; 
				break; 
			}
		}
		if (!cannot_join){
			v.push_back(i);  
			if (!ret) return ret = dfs(x,v); 
			v.pop_back();   
		}
	}
	return ret;  
}
int main(){
	IOFAST(); 
	cin >> K >> N >> F; 
	for (int i = 0; i < F; i++){
		int x,y; 
		cin >> x >> y; 
		grid[x][y] = grid[y][x] = 1; 
	}
	for (int i = 1; i <= N; i++){
		vector<int> v;  
		v.push_back(i);  
		if (dfs(i,v)){
			for (int j = 0; j < ans.size(); j++){
				cout << ans[j] << endl; 
			}
			return 0; 
		}
	}
  // no solution 
	cout << -1 << endl; 
	return 0; 
}
