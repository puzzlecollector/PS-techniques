#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
struct point {
	int x,y; 
}; 
int dist(point &p,point &q){
	return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);  
}
bool cmpPointX(point &p,point &q){
	return p.x < q.x;  
}
bool cmpPointY(point &p,point &q){
	return p.y < q.y;  
}
int solve(point *P,int n){
	if (n == 2) return dist(P[0],P[1]); 
	if (n == 3){
		return min(dist(P[0],P[1]),min(dist(P[0],P[2]),dist(P[1],P[2])));  
	}
	int line = (P[n/2-1].x + P[n/2].x)/2;  
	int d = min(solve(P,n/2),solve(P+n/2,n-n/2));  
	point Mid[n]; 
	int midN = 0; 
	for (int i = 0; i < n; i++){
		int t = line - P[i].x;  // d is the square of distance 
		if (t*t <= d) Mid[midN++] = P[i];  
	}
	sort(Mid,Mid+midN,cmpPointY); 
	for (int i = 0; i < midN; i++){
		for (int j = i+1; j < midN && j <= i+6; j++){
			d = min(d,dist(Mid[i],Mid[j]));  
		}
	}
	return d;  
}
int main(){
	int n; 
	cin >> n; 
	point P[n]; 
	for (int i = 0; i < n; i++){
		cin >> P[i].x >> P[i].y; 
	}
	sort(P,P+n,cmpPointX);  
	cout << solve(P,n) << endl; 
	return 0; 
}
