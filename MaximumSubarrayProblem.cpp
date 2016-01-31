// A divide and conquer approach 
// maximum subarray problem using divide and conquer. 
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <climits> 
using namespace std; 

int a[1000] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7}; 

// Time complexity O(n) 
int findMaxCrossing(int low, int mid, int high){
	int leftSum = INT_MIN; 
	int maxLeft;  
	int sum = 0; 
	for (int i = mid; i >= low; i--){
		sum += a[i];  
		if (sum > leftSum){
			leftSum = sum;  
			maxLeft = i; 
		}
	}
	int rightSum = INT_MIN; 
	int maxRight; 
	sum = 0;  
	for (int j = mid+1; j <= high; j++){
		sum += a[j]; 
		if (sum > rightSum){
			rightSum = sum; 
			maxRight = j;  
		}
	}
	return (leftSum+rightSum); 
}

// The recursive function 
int findMaxSubarray(int low, int high){
	if (low == high){
		// base case: just one element in the array. 
		return a[low]; 
	}
	int mid = (low+high)/2;  
	int leftSum = findMaxSubarray(low,mid); 
	int rightSum = findMaxSubarray(mid+1,high); 
	int crossSum = findMaxCrossing(low,mid,high);  
	if (leftSum >= rightSum && leftSum >= crossSum) return leftSum; 
	else if (rightSum >= leftSum && rightSum >= crossSum) return rightSum; 
	return crossSum; 
}

int main(){
	int n = 16; 
	int ans = findMaxSubarray(0,n);  
	cout << ans << endl; 
	return 0; 
}	


