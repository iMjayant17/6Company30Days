class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans){
        if (root==NULL)return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void merge(vector<int>& v1, vector<int>& v2, vector<int>& ans){
        int i=0, j=0;
        while (i<v1.size() && j<v2.size()){
            if (v1[i]<= v2[j]){
                ans.push_back(v1[i++]);
            }
            else ans.push_back(v2[j++]);
        }
        while (i<v1.size())ans.push_back(v1[i++]);
        while (j<v2.size())ans.push_back(v2[j++]);
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        merge(v1,v2,ans);
        return ans;
    }
};