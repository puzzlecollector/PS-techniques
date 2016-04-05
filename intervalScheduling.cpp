#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <utility> 
#include <vector> 
using namespace std; 

#define MAXN 101 

// inputs
int n,s[MAN],e[MAN]; 
pair<int,int> itv[MAXN];  

int main(){
	for (int i = 0; i < n; i++){
		itv[i].first = e[i];  
		itv[i].second = s[i]; 
	}
	sort(itv,itv+n); 
	int ans = 0, t = 0;  
	for (int i = 0; i < n; i++){
		if (t < itv[i].second){
			++ans; 
			t += itv[i].first; 
		}
	}
	cout << ans << endl; 
	return 0; 
}
