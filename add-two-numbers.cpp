#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* head = NULL;
        ListNode* tail = NULL;

        int sum;
        int carry = 0;

        while(l1 || l2)
        {
            if(l1 && l2)
            {
                sum = (l1->val + l2->val + carry)%10;
                carry = (l1->val + l2->val + carry)/10;

                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1)
            {
                sum = (l1->val + carry)%10;
                carry = (l1->val + carry)/10;

                l1 = l1->next;
            }
            else if(l2)
            {
                sum = (l2->val + carry)%10;
                carry = (l2->val + carry)/10;

                l2 = l2->next;
            }

            ListNode* new_node = new ListNode(sum, NULL);

            if(head == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
            }


        }

        if(carry)
        {
            ListNode* new_node = new ListNode(carry, NULL);

            if(head == NULL)
            {
                head = new_node;
                tail = new_node;
            }
            else
            {
                tail->next = new_node;
                tail = new_node;
            }
        }

        return head;
    }
};

int main()
{
    ListNode* l11 = new ListNode(2, NULL);
    ListNode* l12 = new ListNode(4, NULL);
    ListNode* l13 = new ListNode(3, NULL);
    ListNode* l14 = new ListNode(9, NULL);
    ListNode* l15 = new ListNode(9, NULL);
    ListNode* l16 = new ListNode(9, NULL);
    ListNode* l17 = new ListNode(9, NULL);

    l11->next=l12;
    l12->next=l13;
    //l13->next=l14;
    //l14->next=l15;
    //l15->next=l16;
    //l16->next=l17;
    l13->next=NULL;

    ListNode* l21 = new ListNode(5, NULL);
    ListNode* l22 = new ListNode(6, NULL);
    ListNode* l23 = new ListNode(4, NULL);
    ListNode* l24 = new ListNode(9, NULL);

    l21->next=l22;
    l22->next=l23;
    //l23->next=l24;
    l23->next=NULL;

    Solution s;
    ListNode* l = s.addTwoNumbers(l11, l21);



    while(l)
    {
        cout << l->val;
        l = l->next;
    }

    return 0;
}
