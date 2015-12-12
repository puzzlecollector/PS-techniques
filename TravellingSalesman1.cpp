/*
A complete search algorithm that solves the travelling salesman problem. 
Note that there are n + n(n-1) + n(n-1)(n-2) + ... + n! = O(n!) subproblems, so 
this is algorithmically not a very efficient code. 
This is only the outline, so one should modify this code accordingly in order to compile and run. 

shortestPath(path) = path가 지금까지 담고 있는 경로들의 배열일때 나머지 도시들을 방문하는 모든 경로중에 최소 길이를 반환한다. 
*/
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cmath> 
#include <vector> 
#include <cstring> 
#include <sstream> 
using namespace std; 

int n; // 총 도시의 갯수. The total number of cities.  


double dist[MAXN][MAXN]; // 두 도시간의 거리를 저장하는 배열. Array that stores the distance between the two towns. 

double shortesPath(vector<int>& path, vector<bool>& visited, double currentLength){
	// 기저: 모든 도시를 다 방문했을 때는 시작 도시로 돌아가고 종료한다.  
	// this is the base case: i.e. we visited all the cities, then we return the length and then we stop. 
	if (path.size() == n){
		return currentLength + dist[path[0]][path.back()]; 
	}
	double ret = INF; // initialize to some large value. 
	for (int next = 0; next < n; next++){
		if (visited[next]) continue; 
		int here = path.back(); 
		path.push_back(next); 
		visited[next] = true; 
		double cand = shortesPath(path,visited,currentLength+dist[here][next]); 
		ret = min(ret,cand); 
		visited[next] = false; 
		path.pop_back();  
	}
	return ret;  
}
