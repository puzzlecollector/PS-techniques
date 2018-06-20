#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 
const int MAXN = 1001; 
vector<int> G[MAXN];  
int color[MAXN];  
int V; // number of vertices  
bool dfs(int v,int c){
	color[v] = c;  
	for (int i = 0; i < G[v].size(); i++){
		if (color[G[v][i]] == c) return false;  
		if (color[G[v][i]] == 0 && !dfs(G[v][i],-c)) return false;  
	}
	return true; 
}
void solve(){
	for (int i = 0; i < V; i++){
		if (color[i] == 0){
			if (!dfs(i,1)){
				cout << "NO the graph is not bipartite." << endl; 
				return;  
			}	
		}
	}
	cout << "YES the graph is bipartite." << endl; 
}
