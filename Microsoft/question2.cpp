/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
 
Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> result;
        vector<int> ans;
        getSum(result, ans, k, n, 1);
        return result;
    }
    
    void getSum(vector<vector<int>> &result, vector<int> &ans, int k, int n, int num)
    {
        if(k == 0)
        {
            if(n == 0)
                result.push_back(ans);
            return;
        }
        
        if(num > 9) return;
        
        ans.push_back(num);
        getSum(result, ans, k-1, n-num, num+1);
        ans.pop_back();
        getSum(result, ans, k, n, num+1);
    }
};