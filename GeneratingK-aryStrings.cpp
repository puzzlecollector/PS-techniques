/*
Generating k-ary strings. 
To briefly state the problem: we choose from numbers 0...k-1 in order to make a string of length 
n  that contains the numbers in the range [0,k-1]. 
Of course, there will be k^n such strings in total. 
*/
#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstring> 
using namespace std; 

#define MAX 30 

char A[MAX]; 

void kary(int n, int k){
	if (n < 1){
		printf("%s\n",A); 
		return;  
	}
	for (int i = 0; i < k; i++){
		A[n-1] = i+'0'; 
		kary(n-1,k); 
	}
}

int main(){
	int n,k; 
	printf("Enter values of n and k:");  
	scanf("%d%d",&n,&k);  
	kary(n,k);  
	return 0; 
}

