#include <iostream> 
#include <cstdlib>
#include <string> 
#include <sstream> 
#include <algorithm>
using namespace std; 
 
int makeEqualLength(string &s1, string &s2)
{
    int len1 = s1.length(); 
    int len2 = s2.length(); 
    if (len1 < len2)
    {
        for (int i = 0; i < len2-len1; ++i)
        {
            s1 = '0' + s1; 
        }
        return len2;
    }
    else if (len1 > len2)
    {
        for (int i = 0; i < len1-len2; ++i)
        {
            s2 = '0' + s2;
        }
        return len1; 
    }
    return len1; 
}
 
string addition(string &s1, string &s2)
{
    string result; 
    int length = makeEqualLength(s1,s2); 
    int carry = 0; 
    for (int i = length - 1; i >= 0; --i)
    {
        int firstBit = s1[i] - '0', secondBit = s2[i] - '0'; 
        int sum = (firstBit ^ secondBit ^ carry) + '0';  
        result = char(sum) + result;  
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry); 
    }
    if (carry) result = "1" + result; 
    return result; 
}
 
int main()
{
	int t; 
	cin >> t; 
	while (t--){
		bool flag1 = true, flag2 = true; 
		string s1,s2; 
		cin >> s1 >> s2; 
		// edge case 처리 
  		for (int i = 0; i < s1.length(); ++i)
   		{
    		if (s1[i] != '0')
    		{
    			flag1 = false; 
    			break;
    		}
    	} 
   	 	for (int i = 0; i < s2.length(); ++i)
    	{
    		if (s2[i] != '0')
    		{
    			flag2 = false; 
    			break;
    		}
    	}
    	if (flag1 && flag2)
    	{
    		cout << 0 << endl; 
    		continue;  
    	}   
    	string ans = addition(s1,s2); 
    	if (ans[0] == '0')
    	{
    		int index = 0; 
    		while (ans[index] == '0')
    		{
    			++index; 
    		}
    		for (int i = index; i < ans.length(); ++i)
    		{
    			cout << ans[i]; 
    		}
    		cout << endl;
    	}
   	 	else cout << ans << endl;
	}
    return 0; 
}
