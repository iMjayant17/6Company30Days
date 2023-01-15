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