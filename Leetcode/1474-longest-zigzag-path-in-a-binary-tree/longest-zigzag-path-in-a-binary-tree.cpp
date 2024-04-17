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
    int longestZigZag(TreeNode* root) {
        
        if(root==nullptr)
            return 0;
        int mx =0;
        
        dfs(root,1,mx);
        return mx;
    }
    void dfs(TreeNode* root,int dir,int &mx,int cdp=0) {
        
        if(root==nullptr)
            return ;
        mx = max(mx,cdp);
        if(dir==1)
        {
            dfs(root->left,2,mx,cdp+1);
            dfs(root->right,1,mx,1);
        }
        else {
            dfs(root->left,2,mx,1);
            dfs(root->right,1,mx,cdp+1);
        }
    }
};