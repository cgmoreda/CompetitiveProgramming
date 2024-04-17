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
    vector<vector<int>>t;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        t = vector<vector<int>>(2);
        int d=0;
        dfs(root1,d);
        d=1;
        dfs(root2,d);
        return t[0]==t[1];
    }
    void dfs(TreeNode* root,int &id){
        if(root==nullptr)
            return;
        if(root->left==nullptr&&root->right==nullptr)
            t[id].push_back(root->val);
        
        dfs(root->left,id);
        dfs(root->right,id);
    }
};