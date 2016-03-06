#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std; 

int fail[101];  // assume pattern is of length at most 100
string s,pattern; 

void failureFunction(){
	int len = 0; 
	int i = 1; 
	fail[0] = 0; 
	while (i < (int)pattern.size()){
		if (pattern[i] == pattern[len]){
			len++; 
			fail[i] = len; 
			i++; 
		}else{
			if (len != 0){
				len = fail[len-1]; 
			}else{
				fail[i] = 0; 
				i++; 
  			}
		}
	}
}

int kmp(){
	int n = s.size(), m = pattern.size(); 
	failureFunction();  
	int j = 0;  // index for pattern
	int i = 0; // index for s
	while (i < n){
		if (pattern[j] == s[i]){
			j++; i++; 
		}	
		if (j == m){
			return i-j;  
			j = fail[j-1];  
		}else if (i < n && pattern[j] != s[i]){
			if (j != 0){
				j = fail[j-1];  
			}else{
				i++; 
			}
		}
	}
	return -1; // not found.
}

int main(){
	cin >> s >> pattern; 
	int ans = kmp(); 
	cout << ans << endl; 
}
