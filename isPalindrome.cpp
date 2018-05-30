#include <iostream>
using namespace std; 

bool isPalindrome(string a,int l,int r){
	if (l >= r) return true; 
	if (a[l] != a[r]) return false; 
	return isPalindrome(a,l+1,r-1); 
}
int main(){
	string a; 
	cin >> a; 
	if (isPalindrome(a,0,a.size()-1)) cout << "YES it is a palindrome" << endl;
	return 0; 
}
