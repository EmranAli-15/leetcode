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
    TreeNode* cr = NULL;
    void flatten(TreeNode* root) {


        if (root && root->right) {
            flatten(root->right);
        }

        if (root && root->left) {
            flatten(root->left);
        }

        if(root)
        {
            root->right = cr;
            root->left = NULL;
            cr = root;
        }
    }
};
