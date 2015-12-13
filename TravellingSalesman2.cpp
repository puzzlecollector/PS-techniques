/*
Just a template, need to modify for use. 
A more efficient code that sovles the travelling salesman problem. 
Time complexity O(n2^n)
*/

#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cmath> 
#include <vector> 
#include <cstring> 
#include <sstream> 
using namespace std; 

int n, dist[MAX][MAX];  
double cache[MAX][1 << MAX]; // initialize to -1
double shortesPath2(int here, int visited){
	if (visited == (1 << n)-1) return dist[here][0]; 
	// memoization 
	double& ret = cache[here][visited]; 
	if (ret >= 0) return ret; 
	ret = INF; // initialize ret to a very large value. 
	for (int next = 0; next < n; next++){
		if (visited & (1<<next)) continue; 
		double cand = dist[here][next] + shortesPath2(next,visited); 
		ret = min(ret,cand); 
	}
	return ret; 
}
