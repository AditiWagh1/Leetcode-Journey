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
    bool ispath(TreeNode* root ,int targetsum,int sum)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(root->left==nullptr && root->right==nullptr)
        {
            sum=sum+root->val;
            if(sum==targetsum)
            {
                return true;
            }
        }
        return ispath(root->left,targetsum,sum+root->val)||ispath(root->right,targetsum,sum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
       return ispath(root,targetSum,sum);
    }
};