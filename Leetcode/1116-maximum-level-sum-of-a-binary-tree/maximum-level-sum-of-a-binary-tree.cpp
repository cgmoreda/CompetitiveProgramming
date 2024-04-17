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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level =1;
        int ans=-1,mxval=-2e9;
        while(q.size())
        {
            int sz = q.size(),csum=0;
            while(sz--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node==nullptr)
                    continue;
                csum+=node->val;
                
                if(node->right!=nullptr)
                    q.push(node->right);
                    
                if(node->left!=nullptr)
                    q.push(node->left);
                
            }
            
            if(csum>mxval)
                mxval = csum,ans = level;
            level++;
        }
        return ans;
    }

};