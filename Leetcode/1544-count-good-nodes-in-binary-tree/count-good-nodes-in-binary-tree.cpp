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
    int goodNodes(TreeNode* root,int mxval=-1e4+1) {
        int ret = (root->val)>=mxval;
        mxval = max(mxval,root->val);
        if(root->right!=nullptr)
            ret+=goodNodes(root->right,mxval);
        if(root->left!=nullptr)
            ret+=goodNodes(root->left,mxval);
        return ret;
    }
};