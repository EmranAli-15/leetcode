class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return ans;

        ans.push_back(root->val);
        if(root->left) preorderTraversal(root->left);
        if(root->right) preorderTraversal(root->right);

        return ans;
    }
};
