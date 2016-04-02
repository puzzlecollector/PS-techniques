// dijkstra O(|E|log|V|) time complexity. 
#include <iostream>
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <cstdlib> 
#include <cstring> 
#include <utility>  
using namespace std;
#define MAXV 11111
#define INF 987654321

struct edge{int to,cost;};  
typedef pair<int,int> P; //min_dist,node no.

int V,E; 
vector<edge> G[MAXV];  
int d[MAXV]; 
int previous[MAXV]; 
 
void dijkstra(int s){
	priority_queue<P, vector<P>, greater<P> > que; // pick nodes that have smaller first value (i.e. smaller min_dist value)
	for (int i = 1; i <= V; i++){
		d[i] = INF;  
		previous[i] = -1;  
	}
	d[s] = 0;  
	que.push(P(0,s));  
	while (!que.empty()){
		P p = que.top(); que.pop();  
		int v = p.second;  
		if (d[v] < p.first) continue;  
		for (int i = 0; i < G[v].size(); i++){
			edge e = G[v][i]; 
			if (d[e.to] > d[v]+e.cost){
				d[e.to] = d[v]+e.cost;  
				que.push(P(d[e.to],e.to));  // min_dist, node no. 
				previous[e.to] = v;  
			}
		}
	}
}  

vector<int> get_path(int t){ // shortest path to node t
	vector<int> path; 
	for (; t != -1; t = previous[t]) path.push_back(t); // search until t becomes s. 
	reverse(path.begin(),path.end());  
	return path; 
}

int main(){
	cin >> V >> E;  
	for (int i = 0; i < E; i++){
		// from a to b, with cost p. 
		int a,b,p; 
		cin >> a >> b >> p;  
		edge e; 
		e.to = b, e.cost = p;  
		G[a].push_back(e); // assume the graph is unidirectional. 
	}
	dijkstra(1);  
	vector<int> path = get_path(V);  
	cout << d[V] << endl; 
	for (int i = 0; i < path.size(); i++){
		cout << path[i] << " ";  
	}
	cout << endl; 
	return 0; 
}
