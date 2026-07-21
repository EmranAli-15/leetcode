#include<bits/stdc++.h>
using namespace std;



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> currentLevel;

            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = q.front();
                q.pop();

                currentLevel.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            sort(ans.begin(), ans.end());
            ans.push_back(currentLevel);
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    struct TreeNode* a = new TreeNode();
    struct TreeNode* b = new TreeNode();
    struct TreeNode* c = new TreeNode();
    struct TreeNode* d = new TreeNode();
    struct TreeNode* e = new TreeNode();
    a->val = 3;
    b->val = 9;
    c->val = 20;
    d->val = 15;
    e->val = 7;

    a->left = b;
    a->right = c;
    c->left = d;
    c->right = e;

    Solution s;
    vector<vector<int>> ans = s.levelOrderBottom(a);

    for(int i=0; i<ans.size(); i++)
    {
        cout << "[";
        for(int c:ans[i]) cout << c << " ";
        cout << "]";
    }

    return 0;
}

