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
    bool flag = true;
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            flag = true;
            return true;
        }
        else if((p && !q) || (!p && q))
        {
            flag = false;
            return false;
        }

        if(p->val != q->val)
        {
            flag = false;
            return false;
        }

        cout << p->val << "   " << q->val << endl;

        if(p->left && q->left)
        {
            isSameTree(p->left, q->left);
        }
        else if((p->left && !q->left) || !p->left && q->left)
        {
            flag = false;
            return false;
        }

        if(p->right && q->right)
        {
            isSameTree(p->right, q->right);
        }
        else if((p->right && !q->right) || (!p->right && q->right))
        {
            flag = false;
            return false;
        }

        return flag;
    }
};

int main()
{
    struct TreeNode* root1 = new TreeNode();
    struct TreeNode* root2 = new TreeNode();



    struct TreeNode* two1 = new TreeNode();
    struct TreeNode* two2 = new TreeNode();
    struct TreeNode* three1 = new TreeNode();
    struct TreeNode* three2 = new TreeNode();
    struct TreeNode* four1 = new TreeNode();
    struct TreeNode* four2 = new TreeNode();


    root1->val = 1;
    root2->val = 1;

    two1->val = 2;
    two2->val = 2;
    three1->val = 3;
    three2->val = 3;
    four1->val = 4;
    four2->val = 4;

    root1->left = two1;
    root1->right = three1;

    root2->left = two2;
    root2->right = three2;

    three1->right = four1;
    three2->right = four2;

    Solution s;
    bool ans = s.isSameTree(root1, root2);

    if(ans) cout << "Same.";
    else cout << "Different.";

    return 0;
}

