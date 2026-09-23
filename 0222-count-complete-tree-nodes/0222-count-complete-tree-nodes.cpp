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
// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if(root==nullptr)
//         {
//             return 0;
//         }
//         int leftNodes=countNodes(root->left);
//         int rightNodes=countNodes(root->right);
//         return leftNodes+rightNodes+1;
//     }
// }; //tc =O(n) sc=O(h) but since the input is a complete binary tree O(logn)

//optimal  tc O(logn)
class Solution {
public:
    int getLeftHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->left;
        }
        return h;
    }

    int getRightHeight(TreeNode* node) {
        int h = 0;
        while (node) {
            h++;
            node = node->right;
        }
        return h;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);

        // If left and right heights match, it's a perfect binary tree
        if (lh == rh) {
            return (1 << lh) - 1; // 2^lh - 1
        }

        // Otherwise, recurse on both subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};