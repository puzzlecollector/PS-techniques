/*
Simple recursive C++ code that solves the Towers of Hanoi problem. 
https://en.wikipedia.org/wiki/Tower_of_Hanoi
*/

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
using namespace std;  

void TowersOfHanoi(int n, char fromPeg, char toPeg, char auxPeg){
	if (n == 1){
		printf("Move disk %d from %c to %c\n",n,fromPeg,toPeg);  
		return;  
	}
	TowersOfHanoi(n-1,fromPeg,auxPeg,toPeg);   
	printf("Move disk %d from %c to %c\n",n,fromPeg,toPeg);  
	TowersOfHanoi(n-1,auxPeg,toPeg,fromPeg);  
}

int main(){
	int n; 
	scanf("%d",&n);  
	TowersOfHanoi(n,'A','B','C'); 
	return 0; 
}
