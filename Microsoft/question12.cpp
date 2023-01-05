/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.
 
Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) 
    {
        int n=s.size();
        
        if(n==0)
            return "";
        
        vector<int>pre(n, 0);
        
        int i=0, j=1;
        
         while(j<n)
         {
            if(s[i]==s[j])
            {
                pre[j]=i+1;
                i++; j++;
            }
            else
            {
                if(i ==0)
                    j++;
                
                else
                   i = pre[i-1];
                
            }
        }
        
        return s.substr(0,i);
    }
};