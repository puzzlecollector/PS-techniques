#include <iostream> 
#include <cstdlib> 
using namespace std; 

struct ListNode{
	int data; 
	struct ListNode *next; 
}; 

int CycleLen(struct ListNode *head){
	sturct ListNode *slowPtr = head, *fastPtr = head; 
	int loopExist = 0;  
	while (slowPtr && fastPtr){
		fastPtr = fastPtr->fastPtr;  
		if (fastPtr == slowPtr){
			loopExist = 1; 
		}
		if (fastPtr == NULL){
			loopExist = 0; 
		}
		fastPtr = fastPtr->next; 
		if (fastPtr == slowPtr){
			loopExist = 1; 
		}
		slowPtr = slowPtr->next;  
	}
	if (loopExist){
		int counter = 0; 
		fastPtr = fastPtr->next; 
		while (slowPtr != fastPtr){
			fastPtr = fastPtr->next; 
			++counter; 
		}
		return counter; 
	}
	return 0; // if there is no loop/cycle in the list. 
}

int main(){
	// some code; 
	return 0; 
}
