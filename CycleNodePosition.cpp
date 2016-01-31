// finding the starting node of a cycle in a Linked List.  
#include <iosteam> 
using namespace std; 

struct ListNode{
	int data; 
	struct ListNode *next; 
}; 

struct ListNode *FindBeginOfLoop(struct ListNode *head){
	struct ListNode *slowPtr = head, *fastPtr = head; 
	int loopExists = 0;  
	while (slowPtr && fastPtr){
		fastPtr = fastPtr->next;  
		if (fastPtr == slowPtr){
			loopExists = 1; 
			break; 
		}
		if (fastPtr == NULL){
			loopExists = 0; 
		}
		fastPtr = fastPtr->next;  
		if (fastPtr == slowPtr){
			loopExists = 1; 
			break; 
		}
		slowPtr = slowPtr->next; 
	}
	if (loopExists){
		while (slowPtr != fastPtr){
			fastPtr = fastPtr->next; 
			slowPtr = slowPtr->next; 
		}
		return slowPtr; 
	}
	return NULL;  
}

int main(){
	// some code; 
	return 0; 
}
