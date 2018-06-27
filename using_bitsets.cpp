// example 
#include <iostream>
#include <bitset> 
using namespace std;  
int main(){
	bitset< 1<<25 > s; 
	int x; 
	while (cin >> x){
		if (!s.test(x)){
			cout << x << " ";  
			s.set(x);  
		}
	}
	cout << endl; 
	return 0;  
}
