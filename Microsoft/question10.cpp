/*
Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.
Return the shortest such subarray and output its length.
 
Example 1:
Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> tmp;
        tmp = nums;
        sort(tmp.begin(),tmp.end());
        int n = nums.size();
         int i = 0;
         int j =  n-1;
        for(;i<n;i++)
        {
            if(nums[i]!=tmp[i])
                break;
        }
        
        for(;j>=0;j--)
        {
            if(nums[j]!=tmp[j])
                break;
        }
        int ans=0;
        for(int k=i;k<=j;k++){
            ans++;
            }
        return ans;
    }
};