#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm> 
#include <vector> 
using namespace std;  
typedef long long ll;  // just to be safe 
typedef vector<ll> vec; 
typedef vector<vec> mat;  
const ll mod = 1000; 
// multiply matrix A and B 
mat multiply(mat A,mat B){
	mat C(A.size(),vec(B[0].size()));
	for (int i = 0; i < A.size(); i++){
		for (int j = 0; j < B.size(); j++){
			for (int k = 0; k < B[0].size(); k++){
				C[i][j] = (C[i][j] + A[i][k]*B[k][j])%mod; 
			}
		}
	} 
	return C;   
}
mat fast_exponentiation(mat A,ll n){
	// B is the identity matrix 
	mat B(A.size(),vec(A[0].size()));  
	for (int i = 0; i < A.size(); i++){
		B[i][i] = 1;  
	}
	while (n > 0){
		if (n&1) B = multiply(B,A);  
		A = multiply(A,A); 
		n >>= 1;  
	}
	return B; 
}	
int main(int argc,char ** argv){
	ll N,b; // calculate A^b
	scanf("%lld %lld",&N,&b);  
	mat A(N,vec(N)); 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%lld",&A[i][j]);  
		}
	}
	A = fast_exponentiation(A,b); 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%lld ",A[i][j]);  
		}
		printf("\n");  
	}
	return 0; 
}
