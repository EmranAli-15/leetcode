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
class BSTIterator {
public:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* x = s.top();
        s.pop();

        TreeNode* cur = x->right;
        while(cur)
        {
            s.push(cur);
            cur = cur->left;
        }

        return x->val;
    }

    bool hasNext() {
        if(!s.empty()) return true;
        return false;
    }
};
