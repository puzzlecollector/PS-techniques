/*
Print all binary strings of length n. 
Of course, there will 2^n such strings in total. 
*/
#include <iostream> 
#include <cstring> 
#include <cstdio> 
using namespace std; 

#define MAX 30

char A[MAX]; 

void binary(int n){
	if (n < 1){
		printf("%s\n",A); 
		return; 
	}
	A[n-1] = '0'; 
	binary(n-1); 
	A[n-1] = '1'; 
	binary(n-1);  
}

int main(){
	printf("Enter a value of n ≤ 30\n"); 
	int n; 
	scanf("%d",&n);
	binary(n); 
	return 0; 	 
}
