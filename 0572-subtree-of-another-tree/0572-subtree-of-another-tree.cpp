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
    bool isSame(TreeNode* p,TreeNode* q)
    {
        if(p==nullptr || q==nullptr)
        {
            return p==q;
        }
        int left=isSame(p->left,q->left);
        int right=isSame(p->right,q->right);
        return left && right && p->val==q->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr ||subRoot==nullptr)
        {
            return root==subRoot;
        }
        if(root->val==subRoot->val  && isSame(root,subRoot))
        {
            return true;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
    }
};