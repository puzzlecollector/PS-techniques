#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std;  

int n; 
unsigned char sieve[(MAX_N+7)/8]; 
// k가 소수인지 확인한다 
inline bool isPrime(int k){
	return sieve[k >> 3]&(1<<(k&7)); 
}
// k가 소수가 아니라고 표시한다 
inline void seComposite(int k){
	sieve[k >> 3] &= ~(1<<(k&7)); 
}

//비트마스크를 사용하는 에라토스  
void eratosthenes(){
	memset(sieve,255,sizeof(sieve)); 
	seComposite(0); 
	seComposite(1); 
	int sqrtn = int(sqrt(n)); 
	for (int i = 2; i <= sqrtn; i++){
		// 이 수가 아직 지워지지 않았다면 
		if(isPrime(i)){
			for(int j = i*i; j <= n; j += i){
				seComposite(j); 
			}
		}
	}
} 
