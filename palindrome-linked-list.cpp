#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next = NULL;
};


class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* n = slow->next;
        ListNode* p = NULL;
        ListNode* c = slow->next;

        while(n && n->next)
        {
            c = n;
            n = n->next;
            c->next = p;
            p = c;
        }

        if(n)
        {
            n->next = p;
            slow->next = n;
        }
        else n = slow;

        while(n)
        {
            if(n->val != head->val) return false;
            head = head->next;
            n = n->next;
        }
        return true;
    }
};




int main()
{
    struct ListNode* a = new ListNode();
    struct ListNode* b = new ListNode();
    struct ListNode* c = new ListNode();
    struct ListNode* d = new ListNode();
    struct ListNode* e = new ListNode();
    struct ListNode* f = new ListNode();
    struct ListNode* g = new ListNode();

    a->val = 1;
    b->val = 2;
    c->val = 2;
    d->val = 1;
    e->val = 5;
    f->val = 6;
    g->val = 7;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = g;



    Solution s1;

    cout << s1.isPalindrome(a);

    return 0;
}
