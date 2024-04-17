/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ret;
        dfs(root,ret,0);
        return ret;
    }
    void dfs(TreeNode* node,vector<int>&see,int depth)
    {
        if(node==nullptr)
            return;
        if(depth==see.size())
            see.push_back(node->val);
        dfs(node->right,see,depth+1);
        dfs(node->left,see,depth+1);
    }
};