#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <vector> 
#include <queue> 
using namespace std; 
typedef pair<int,int> P;  
const int MAX_N = 1001;  
struct edge {int from,to,cost;};  
int N,R; // input  
vector<edge> G[MAX_N];  
int dist[MAX_N]; // stores shortest path 
int dist2[MAX_N]; // stores second shortest path 
void solve(){
	priority_queue< P,vector<P>,greater<P> > pq; 
	fill(dist,dist+N,INF);  
	fill(dist2,dist2+N,INF); 
	dist[0] = 0; 
	que.push(P(0,0)); 
	while (!que.empty()){
		P p = que.top(); que.pop(); 
		int v = p.second, d = p.first;  
		if (dist2[v] < d) continue; 
		for (int i = 0; i < G[v].size(); i++){
			edge &e = G[v][i]; 
			int d2 = d + e.cost; 
			if (dist[e.to] > d2){
				swap(dist[e.to],d2); 
				que.push(P(dist[e.to],e.to));  
			}
			if (dist2[e.to] > d2 && dist[e.to] < d2){
				dist2[e.to] = d2; 
				que.push(P(dist2[e.to],e.to));  
			}
		}
	}
	printf("%d\n",dist2[N-1]);  
}
