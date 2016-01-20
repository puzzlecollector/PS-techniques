// code that demonstrates how sorting is done based on multiple criteria. 
#include <iostream> 
#include <algorithm> 
using namespace std; 

#define mp make_pair  // macro for simpler code.  

typedef pair<int,int> P; 

bool cmp(P& p1, P& p2){
	// this callback function sorts objects in array such that smaller values of pair.first comes first, but 
	// if the two values are the same, then sorts such that the smaller value of pair.second comes first. 
	return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second)); 
}

int main(){
	P a[5] = {mp(3,4), mp(3,5), mp(1,7), mp(2,8), mp(1,2)};  
	sort(a,a+5,cmp);  
	// check by printing out the results. 
	for (int i = 0; i < 5; i++){
		cout << a[i].first << " " << a[i].second << endl; 
	}
	return 0; 
}
