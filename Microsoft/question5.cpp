/*
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.
 
Example 1:
Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n,1) , hash(n);
        int maxi = 1;
        int lastindex = 0;
        sort(nums.begin() , nums.end());
        for(int i=0;i<n;i++){
            hash[i] = i;
            for(int prv = 0; prv<i;prv++){
                if(nums[i]%nums[prv] == 0 && 1 + dp[prv] > dp[i]){
                    dp[i] = 1 + dp[prv];
                    hash[i] = prv ; 
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastindex  = i;
            }
        }
        vector<int> tmp;
        tmp.push_back(nums[lastindex]);
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            tmp.push_back(nums[lastindex]);
        }
        reverse(tmp.begin(),tmp.end());
        return tmp;

    }
};