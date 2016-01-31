// Detecting cycle in a linked list. 
// Example Code 
#include <iostream> 
#include <cstdlib> 
using namespace std; 

struct ListNode{
	int data; 
	struct ListNode *next;  
}; 

int IsLinkedListContainsLoop(struct ListNode *head){
	struct ListNode *slowPtr = head, *fastPtr = head; 
	while (slowPtr && fastPtr){
		fastPtr = fastPtr->next; 
		if (fastPtr == slowPtr) return 1; 
		if (fastPtr == NULL) return 0; 
		fastPtr = fastPtr->next; 
		if (fastPtr == slowPtr) return 1; 
		slowPtr = slowPtr->next; 
	}
	return 0; 
}

int main(){
	// some code; 
	return 0; 
}
