/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least one occurrence of all these characters a, b and c.
 
Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0,ans=0;
        
        vector<int> v (3,0);
        for(int j=0; j<s.length();j++){
            v[s[j]-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0 && i<=j){
                 v[s[i]-'a']--;
                ans+=(s.length() - j);
                i++;
        
            }
        }
        return ans;
    }
};