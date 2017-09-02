#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
using namespace std;
int imin3(int a,int b,int c){
	int minval = min(a,min(b,c)); 
	if (minval == a) return 0;  
	else if (minval == b) return 1; 
	return 2; 
}
int min3(int a,int b,int c){
	return min(a,min(b,c)); 
}
typedef pair<char,char> P; 
int editDistDP(string str1, string str2){
	// all operations are though to be done on str1 
    int m = str1.length();
    int n = str2.length();
    int dp[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;
            } else if (j == 0) {
                dp[i][j] = i;
            } else if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {            
                dp[i][j] = 1 + min3(dp[i][j - 1],
                                    dp[i - 1][j],
                                    dp[i - 1][j - 1]);
            }
        }
    }
    vector<P> v;  
    i = m; j = n;
    while (i || j) {
        if (i == 0) {
        	v.push_back(P('a',str2[j-1])); 
            //cout << "a " << str2[j - 1] << endl;
            j--;
        } else if (j == 0) {
            //cout << "d " << str1[i - 1] << endl;
            i--;
        } else if (str1[i - 1] == str2[j - 1]) {
        	v.push_back(P('c',str1[i-1]));  
        	//cout << "c " << str1[i-1] << endl; 
            i--; j--;
        } else {        
            int k = imin3(dp[i][j - 1],
                          dp[i - 1][j],
                          dp[i - 1][j - 1]);
            if (k == 2) {
                //cout << "replace " << str1[i - 1] 
                  //   << " with " << str2[j - 1] << endl;
            	v.push_back(P('m',str2[j-1])); 
            	//cout << "m " << str2[j-1] << endl; 
                i--; j--;
            } else if  (k == 1) {
               	//cout << "d " << str1[i - 1] << endl;
                i--;
            } else {
            	v.push_back(P('a',str2[j-1]));  
                //cout << "a " << str2[j - 1] << endl;
                j--;
            }
        }
    }
    for (int i = v.size()-1; i >= 0; i--){
    	cout << v[i].first << " " << v[i].second << endl; 
    }
    return dp[m][n];
}
int main(){
	string s1,s2;  
	getline(cin,s1); 
	getline(cin,s2); 
	int ans = editDistDP(s1,s2); 
	return 0;  
}
