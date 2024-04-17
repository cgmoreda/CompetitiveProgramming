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
    map<long long,int> mp;
    int pathSum(TreeNode* root, int targetSum,long long csum=0,int firs=1) {
        if(root==nullptr)
            return 0;
        if(firs){
            mp.clear();
            mp[0]=1;
        }
        int ret =0;
        csum+=root->val;
        if(mp.count(csum-targetSum))
            ret+=mp[csum-targetSum];
        mp[csum]++;
        
        ret+=pathSum(root->left,targetSum,csum,0);
        ret+=pathSum(root->right,targetSum,csum,0);
        mp[csum]--;
        return ret;
    }
};