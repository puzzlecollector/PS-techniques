// Problem Using KMP. 
// Problem Link: https://www.acmicpc.net/problem/5525 
// From 2009 Japan Olympiad in Informatics
#include <iostream>
#include <string> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

#define MAXL 1000001

int PartialMatchTable[MAXL];  
int cnt; 

void computePartialMatchTable(string pattern){
	int len = 0;  
	int i = 1;  
	int m = pattern.size();  
	// calculates longest proper prefix that matches a proper suffix  
	while (i < m){
		if (pattern[i] == pattern[len]){
			len++;  
			PartialMatchTable[i] = len;  
			i++;  
		}else if (pattern[i] != pattern[len]){
			if (len != 0){
				len = PartialMatchTable[len-1];   
			}else if (len == 0){
				PartialMatchTable[i] = 0;  
				i++;  
			}
		}
	}
}

void KMPSearch(string given, string pattern){
	computePartialMatchTable(pattern);
	int n = given.size(), m = pattern.size();  
	int i = 0; // index for given. 
	int j = 0;  // index for pattern.
	while (i < n){
		if (pattern[j] == given[i]){
			j++;  i++;  
		}
		if (j == m){
			++cnt;  
			j = PartialMatchTable[j-1];  
		}else if (i < n && pattern[j] != given[i]){
			if (j != 0){
				j = PartialMatchTable[j-1]; 
			}else{
				++i;  
			}
		}
	}
}

int main(){
	int N,M; 
	string given; 
	cin >> N >> M >> given;  
	string s = ""; 
	for (int i = 0; i < N; i++){
		s += "IO"; 
	}
	s += "I";  
	// note that s is our pattern. 
	KMPSearch(given,s); 
	cout << cnt << endl; 
	return 0; 
}
