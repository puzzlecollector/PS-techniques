#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <stack> 
using namespace std; 
typedef long long ll;  
struct Point{
	ll x,y; 
};  
// a global poin tneeded for sorting points with reference 
// to the first point used in compare function of qsort() 
Point p0;  
// utility function to find the point next to the last point 
// on our stack 
Point nextToTop(stack<Point> &s){
	Point p = s.top(); s.pop(); 
	Point res = s.top();  
	s.push(p); 
	return res;  
}
// a utility funciton to swap two points 
void swap(Point &p1,Point &p2){
	Point temp = p1; 
	p1 = p2; 
	p2 = temp; 
}
// a utility function ot return square of distnace 
// between p1 and p2 
ll distSq(Point p1,Point p2){
	return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y); 
}
// finding the orientation of three points 
int orientation(Point p1,Point p2,Point p3){
	ll val = (p2.y-p1.y)*(p3.x-p2.x) - (p2.x-p1.x)*(p3.y-p2.y); 
	if (val == 0) return 0; 
	return (val > 0) ? 1 : 2;  
}
// function used by qsort() to sort an array of points with 
// respect to the first point 
int compare(const void *vp1,const void *vp2){
	Point *p1 = (Point *)vp1; 
	Point *p2 = (Point *)vp2; 
	int o = orientation(p0,*p1,*p2);
	if (o == 0) return (distSq(p0,*p2) >= distSq(p0,*p1)) ? -1 : 1; 
	return (o == 2) ? -1 : 1;  
}
// prints convex hull of a set of n points 
int convexHull(Point points[],int n){
	// find bottommost point 
	ll ymin = points[0].y, minidx = 0;
	for (int i = 1; i < n; i++){
		ll y = points[i].y; 
		if ((y < ymin) || (ymin == y && points[i].x < points[minidx].x)){
			minidx = i;  
			ymin = points[i].y;  
		}
	}  
	// place bottom-most point at the first position 
	swap(points[0],points[minidx]); 
	// sort n-1 points with repsect to the first point  
	// a point p1 comes before p2 in sorted output if p2 has larger 
	// polar angle in counter clockwise direction than p1.  
	p0 = points[0]; 
	qsort(&points[1],n-1,sizeof(Point),compare); 
	// if two or more points make same angle with p0
	// remove all but the one that is farthest from p0 
	// remember that in above sorting, our criteria was 
	// to keep the farthest point at the end when more than 
	// one points have the same angle. 
	int m = 1;  
	for (int i = 1; i < n; i++){
		// keep removing i while angle of i and i+1 is same with respect to p0
		while (i < n-1 && orientation(p0,points[i],points[i+1]) == 0){
			i++;  
		}
		points[m] = points[i];  
		m++;  
	}
	if (m < 3) return -1; // impossible 
	stack<Point> S; 
	S.push(points[0]); 
	S.push(points[1]); 
	S.push(points[2]); 
	for (int i = 3; i < m; i++){
		// keep removing top while the angle formed by 
		// points next-to-top, top, and points[i] makes 
		// a non-left turn 
		while (orientation(nextToTop(S),S.top(),points[i]) != 2){
			S.pop(); 
		}
		S.push(points[i]); 
	}
	return S.size();  
}
Point points[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> points[i].x >> points[i].y; 
	}
	int ans = convexHull(points,n); 
	cout << ans << endl; 
	return 0; 
}
