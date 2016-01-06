// referred to geeks for geeks 
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

int n; 

int solve(){
	int der[n+1];  
	der[0]=1; 
	der[1]=0; 
	der[2]=1; 
	// fill der table from bottom up method. 
	for (int i = 3; i <= n; i++){
		der[i] = (i-1)*(der[i-1]+der[i-2]); 
	}
	// return ans 
	return der[n]; 
}

int main(){
	cin >> n; 
	int ans = solve(); 
	cout << "the number of derangements " << ans << "." << endl; 
	return 0; 
}
