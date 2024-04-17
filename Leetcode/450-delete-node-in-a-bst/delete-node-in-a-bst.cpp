/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        dostuff(root, nullptr, key);
        if (root && root->val == key)
        {
            if(root->right)
                return root->right;
            else
                return root->left;
        }
        return root;
    }
    void dostuff(TreeNode* node, TreeNode* par, int key) {
        if (node == nullptr)
            return;
        if (node->val == key) {
            if(node->right){   
                if (par) {
                    if (par->right == node)
                        par->right = node->right;
                    if (par->left == node)
                        par->left = node->right;
                }
                TreeNode* farleft = node->right;
                while (farleft && farleft->left)
                    farleft = farleft->left;
                if(farleft)
                    farleft->left = node->left;
            }
            else {
                  if (par) {
                    if (par->right == node)
                        par->right = node->left;
                    if (par->left == node)
                        par->left = node->left;
                }
            }
            return;
        }
        dostuff(node->left, node, key);
        dostuff(node->right, node, key);
    }
};