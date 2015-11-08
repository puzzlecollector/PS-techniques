/*Karatsuba fast multiplication. Program not fully tested and optimized yet. 
Suppose we were to multiply two big numbers (each more than 50 digits long). Then the following is a divide 
and conquer method that supposedly runs in O(n^lg3) time. 
카라츠바 빠른 곱셈 알고리즘: karatsuba() 함수는 종만북 챕터7 참고
*/

#include <iostream>
#include <cstdio>
#include <vector> 
#include <algorithm> 
#include <cstdlib>
#include <string>
using namespace std; 
// karatsuba 빠른 곱셈 구현하기
// num[]의 자릿수 올림을 처리한다. 
void normalizeMult(vector<int>& num){
	num.push_back(0); 
	// 자릿수 올림을 처리!! 
	for (int i = 0; i < num.size(); i++){
		if (num[i] < 0){
			int borrow = (abs(num[i])+9)/10; 
			num[i+1] -= borrow; 
			num[i] += borrow*10; 
		}else{
			num[i+1] += num[i]/10;  
			num[i] %= 10;  
		}
	}
	while (num.size() > 1 && num.back() == 0){
		num.pop_back(); 
	}
}

// 두 자연수의 곱을 반환한다. 
// 각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다. 
// 에: multiply({3,2,1},{6,5,4} = 123*456 = 56088 = {8,8,0,6,5})
vector<int> multiply(const vector<int>& a, const vector<int>& b){
	vector<int> c(a.size()+b.size()+1,0); 
	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < b.size(); j++){
			c[i+j] += a[i]*b[j]; 
		}
	}
	normalizeMult(c); 
	return c; 
}

// 두 자연수의 덧셈을 한뒤에 올림을 해준다.  
vector<int> normalizeAdd(vector<int>& num){
	for (int i = 0; i < num.size(); i++){
		num[i+1] += num[i]/10; 
		num[i] %= 10; 
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back(); 
	return num; 
}


// a += b*(10^k)를 구현한다. 
void addTo(vector<int>& a, const vector<int>& b, int k){
	vector<int> newb; 
	for (int i = 0; i < k; i++){
		newb.push_back(0); 
	}
	for (int i = 0; i < b.size(); i++){
		newb.push_back(b[i]);  
	}
	vector<int> c(a.size()+newb.size()+1,0);  
	for (int i = 0; i < min(a.size(),newb.size()); i++){
		c[i] += a[i]+newb[i]; 
	}
	vector<int> longer;  
	if (a.size() >= newb.size()) longer = a; 
	else longer = newb; 
	for (int i = min(a.size(),newb.size()); i < max(a.size(),newb.size()); i++){
		c[i] += longer[i]; 
	}
	// 백터 a를 업데이트함 
	a = normalizeAdd(c); 
}

// a -= b에서 자릿수 올림을 구현한다. 
vector<int> normalizeSub(vector<int>& num){
	for (int i = 0; i < num.size(); i++){
		if (num[i] < 0){
			num[i] += 10; 
			num[i+1] -= 1; 
		}
	}
	while (num.size() > 1 && num.back() == 0) num.pop_back(); 
	return num; 
}


// a -= b 를 구현한다. a >= b를 가정한다. 
void subFrom(vector<int>& a, const vector<int>& b){
	vector<int> c(a.size(),0);  
	for(int i = 0; i < b.size(); i++){
		c[i] += a[i]-b[i];  
	}
	a = normalizeSub(c); 
}

vector<int> karatsuba(vector<int>& a, vector<int>& b){
	int an = a.size(), bn = b.size(); 
	// a가 b보다 짧을경우, 둘을 바꾼다. 
	if (an < bn) return karatsuba(b,a);
	// 기저: a 또는 b가 비어있을때 
	if (an == 0 || bn == 0) return vector<int>(); 
	// a의 길이가 충분히 짧을때, 단순 곱셈 연산으로 바꾼다. 
	if (an <= 50) return multiply(a,b);  
	int half = an/2; 
	// 분할정복 (divide and conquer) 시작함
	vector<int> a0(a.begin(),a.begin()+half); 
	vector<int> a1(a.begin()+half,a.end()); 
	vector<int> b0(b.begin(),b.begin()+min<int>(b.size(),half));  
	vector<int> b1(b.begin()+min<int>(b.size(),half),b.end());  
	// z2 = a1*b1 
	vector<int> z2 = karatsuba(a1,b1); 
	// z0 = a0*b0 
	vector<int> z0 = karatsuba(a0,b0); 
	// a0 = a0 + a1, b0 = b0 + b1 update 
	addTo(a0,a1,0); 
	addTo(b0,b1,0); 
	// z1 = (a0*b0)-z0-z1 
	vector<int> z1 = karatsuba(a0,b0); 
	subFrom(z1,z0); 
	subFrom(z1,z2); 
	// ret = z0 + z1*10^half + z2*10^(half*2) 
	vector<int> ret; 
	addTo(ret,z0,0); 
	addTo(ret,z1,half); 
	addTo(ret,z2,half+half); 
	return ret; 
}

int main(){
	vector<int> a,b,res; 
	string s; 
	cout << "Enter the first number:"; 
	cin >> s; 	
	reverse(s.begin(),s.end()); 
	for (int i = 0; i < s.length(); i++){
		int num = s[i]-'0'; 
		a.push_back(num); 
	}
	cout << "Enter the second number:"; 
	cin >> s; 
	reverse(s.begin(),s.end()); 
	for (int i = 0; i < s.length(); i++){
		int num = s[i]-'0'; 
		b.push_back(num); 
	}
	res = karatsuba(a,b); 
	reverse(res.begin(),res.end()); 
	for (vector<int>::size_type i = 0; i < res.size(); i++){
		cout << res[i]; 
	}
	cout << endl;
	return 0; 
}
