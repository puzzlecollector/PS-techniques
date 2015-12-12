/*
Given a vector containing a permutation from 1 to n (n ≤ 11, or else there will be an int overflow)
find the position this permutation belongs to when we list all the permutations from 1 to n in 
sorted order.  
*/
#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <cmath> 
using namespace std; 

int factorial[12]; 

void calcFactorial(){
	factorial[0] = 1;  
	factorial[1] = 1; 
	for (int i = 2; i < 12; i++){
		factorial[i] = i*factorial[i-1]; 
	}
}

// find the position of X in the sorted list of permutations. 
int getIndex(const vector<int>& X){
	int ret = 0;  
	for (int i = 0; i < X.size(); i++){
		int less = 0; 
		for (int j = i+1; j < X.size(); j++){
			if (X[j] < X[i]) ++less;  
		}
		ret += factorial[X.size()-i-1]*less; 
	}
	return ret;  
}

int main(){
	calcFactorial(); 
	// testing ! 
	vector<int> X; 
	X.push_back(4); 
	X.push_back(5); 
	X.push_back(1); 
	X.push_back(2); 
	X.push_back(3); 
	for (int i = 6; i <= 10; i++){
		X.push_back(i+1); 
	}
	// now the vector contains {4,5,1,2,3,6,7,8,9,10}
	int idx = getIndex(X);  
	cout << idx << endl;
	return 0; 
}
