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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        dfs(root,p,q,ans);
        return ans;
    }

    int dfs(TreeNode* node,TreeNode* &p, TreeNode* &q,TreeNode* &ans){
        if(node==nullptr)
            return 0;
        TreeNode* tmp = ans; 
        
        int ret = (node==p)|(node==q)<<1;
        ret|=dfs(node->right,p,q,ans)|dfs(node->left,p,q,ans);
        if(ret==3&&tmp==ans)
            ans = node;
        return ret;
    }
};