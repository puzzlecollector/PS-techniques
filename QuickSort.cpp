#include <iostream> 
#include <string> 
#include <algorithm> 
#include <cstdlib> 
#include <cstdio> 
using namespace std; 

// expected running time O(nlogn) quicksort algorithm. 

int Partition(int arr[], int n){
	int lh = 1, rh = n-1;  
	int pivot = arr[0]; 
	while (true){
		while (lh < rh && arr[rh] >= pivot) rh--;  
		while (lh < rh && arr[lh] <= pivot) lh++; 
		if (lh == rh) break; 
		swap(arr[lh],arr[rh]); 
	}
	if (arr[lh] >= pivot) return 0; 
	swap(arr[0],arr[lh]);  
	return lh; 
}

void QuickSort(int arr[], int n){
	if (n < 2) return; 
	int boundary = Partition(arr,n);  
	// sort subarray up to pivot. 
	QuickSort(arr,boundary);  
	// sort subarry from pivot to end. 
	QuickSort(arr+boundary+1,n-boundary-1); 
}

int main(){
	int a[6] = {5,1,4,3,11,10}; 
	QuickSort(a,6);  
	for (int i = 0; i < 6; i++){
		printf("%d ",a[i]);  
	}
	printf("\n"); 
	return 0; 
}
