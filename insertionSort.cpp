#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
using namespace std; 

void insertionSort(int a[],int n){
	for (int i = 2; i < n; i++){
		int key = a[i]; 
		int j = i-1; 
		while (j > 0 && a[j] > key){
			a[j+1] = a[j];  
			--j;  
		}
		a[j+1] = key; 
	}
}

int main(){
	int a[5] = {1,4,3,7,5};  
	insertionSort(a,5);  
	// print for checking  
	for (int i = 0; i < 5; i++){
		printf("%d ",a[i]);  
	}
	printf("\n"); 
	return 0; 
}
