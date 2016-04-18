// The N-Queens Problem 
// reference: wikibooks 
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std; 
 
int N,cnt=0; 
int position[15];  
 
// check if a position is safe 
bool isSafe(int queen_number, int row_position){
    // check each queen before this one 
    for (int i = 0; i < queen_number; i++){
        // get another queen's row_position
        int other_row_pos = position[i];  
        if (other_row_pos == row_position || other_row_pos == row_position - (queen_number-i) || other_row_pos == row_position + (queen_number-i)){
            return false; 
        }
    }
    return true;  
}
 
// recursively generate a tuple 
void solve(int k){
    if (k == N){
        ++cnt;  
    }
    else {
        for (int i = 0; i < N; i++){
            if (isSafe(k,i)){
                position[k] = i; 
                solve(k+1);  
            }
        }
    }
}
 
int main(){
    scanf("%d",&N);  
    solve(0); 
    printf("%d\n",cnt); 
    return 0; 
}
