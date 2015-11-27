#include <iostream>
#include <cstdlib> 
#include <cstring> 
#include <vector> 
#include <algorithm> 
using namespace std;  

int n; // length of the longest increasing subsequence.  
int S[101], cache[101], choices[101]; 
int lis4(int start){
	// memoization
	int& ret = cache[start+1]; 
	if (ret != -1) return ret; 
	// S[start]가 있어서 적어도 하나는 있다.  
	ret = 1; 
	int bestNext = -1;  
	for (int next = start+1; next < n; next++){
		if (start == -1 || S[start] < S[next]){
			int cand = lis4(next)+1;  
			if (ret < cand){
				ret = cand; 
				bestNext = next;  
			}
		}
	}
	choices[start+1] = bestNext;  
	return ret;  
}

void reconstruct(int start, vector<int>& seq){
	if (start != -1) seq.push_back(S[start]);  
	int next = choices[start+1]; 
	if (next != -1) reconstruct(next,seq); 
}

int main(){
	memset(cache,-1,sizeof(cache));  
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> S[i];  
	}
	lis4(-1);  
	vector<int> seq;  
	reconstruct(-1,seq);  
	for (int i = 0; i < seq.size(); i++){
		cout << seq[i] << " "; 
	}
	cout << endl; 
	return 0; 
}
