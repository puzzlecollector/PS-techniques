#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
#include <cstring> 
#include <vector> 
using namespace std; 
int gcd(int a,int b){
	if (b == 0) return a; 
	return gcd(b,a%b); 
}
bool prime(int x){
	for (int i = 2; i*i <= x; i++){
		if (x%i == 0) return false; 
	}
	return true; 
}
int phi(int x){
	if (prime(x)) return x-1; 
	for (int i = 2; i <= x; i++){
		if (x%i == 0){
			if (gcd(i,x/i) > 1){
				return i*phi(x/i); 
			}else{
				return phi(i)*phi(x/i);  
			}
		}
	}
	return -1; // should not reach this step 
}
int main(){	 
	int n;  
	while (1){	
		scanf("%d",&n); 
		if (n == 0) break; 
		printf("%d\n",phi(n));  
	}
	return 0; 
}	
