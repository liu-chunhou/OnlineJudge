/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*, int> dp;
public:
    int rob(TreeNode* root) {
        if(root==nullptr)return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        int ans=root->val;
        if(root->left!=nullptr)ans+=rob(root->left->left) + rob(root->left->right);
        if(root->right!=nullptr)ans+=rob(root->right->left) + rob(root->right->right);
        ans=max(ans, rob(root->left)+rob(root->right));
        dp[root]=ans;
        return ans;
    }
};