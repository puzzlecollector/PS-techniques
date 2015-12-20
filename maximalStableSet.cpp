// 극대 안정 집합 문제를 해결하는 예제 코드 
// this is just a template, we have to modify for use 
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
using namespace std; 

int n; 
// explodes[i]는 물건 i와 같이 두면 폭발하는 물건들의 목록이다. 
int explodes[i];  

bool isStable(int set){
	for (int i = 0; i < n; i++){
		if (set&(1<<i) && (set&explodes[i])){
			return false; 
		}
	}
	return true; 
}

int countStableSet(){
	int ret = 0; 
	for (int set = 1; set < (1<<n); set++){
		if  (!isStable(set)) continue; 
		bool canExtend = false;  
		for (int add = 0; add < n; add++){
			if ((set&(1<<add)) && (explodes[add]&set == 0)){
				canExtend = true; 
				break; 
			}
		}
		if (!canExtend) ++ret; 
	}
	return ret; 
}

int main(){
	// some code 
	return 0; 
}
