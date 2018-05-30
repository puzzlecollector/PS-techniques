#include <iostream>
#include <cstdlib>
#include <algorithm>
// choose min intervals covering from march 1st to november 30
#include <vector> 
using namespace std; 
typedef pair<int,int> P;  
P a[100005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		int u,v,r,t;  
		cin >> u >> v >> r >> t; 
		a[i].first = u*100+v; 
		a[i].second = r*100+t; 
	}
	sort(a,a+n); 
	int ans = 0;  
	int start = 301; // march 1st  
	int end = 0;
	int idx = -1; 
	int chose = 0;  
	while (start <= 1130 && idx < n){
		chose = 0;
		idx++; 
		for (int j = idx; j < n; j++){
			if (a[j].first > start) break; 
			if (a[j].second > end){
				end = a[j].second; 
				chose = 1; 
				idx = j; 
			}
		}
		if (chose){
			start = end; 
			ans++; 
		}else{
			cout << 0 << endl; 
			return 0;  
		}
	}
	cout << ans << endl; 
	return 0; 
}
