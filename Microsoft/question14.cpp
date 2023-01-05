/*
You are given two positive integer arrays nums and numsDivide. You can delete any number of elements from nums.
Return the minimum number of deletions such that the smallest element in nums divides all the elements of numsDivide. If this is not possible, return -1.
Note that an integer x divides y if y % x == 0.
 
Example 1:
Input: nums = [2,3,2,4,3], numsDivide = [9,6,9,3,15]
Output: 2
Explanation: 
The smallest element in [2,3,2,4,3] is 2, which does not divide all the elements of numsDivide.
We use 2 deletions to delete the elements in nums that are equal to 2 which makes nums = [3,4,3].
The smallest element in [3,4,3] is 3, which divides all the elements of numsDivide.
It can be shown that 2 is the minimum number of deletions needed.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int minOperations(vector<int>& nums, vector<int>& numsDivide) {
			int ans=0;
			map<int,int> mp;
			for(auto x:nums)
				mp[x]++;

			for(auto x:mp){
				int div=0;
				for(auto y:numsDivide){
					if(y%x.first!=0){
					
						div=1;
						break;
					}
				}
				
				if(div==1){
					ans+=x.second;
				}else{
					return ans;
				}
			}
			
			return -1;
		}
	};