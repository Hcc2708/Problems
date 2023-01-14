/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode;
        l3->next = NULL;
        ListNode *l4 = l3;
        while(l1 != NULL && l2 != NULL) {
            ListNode *n = new ListNode;
            n->next = NULL;
            if((l1->val + l2->val) > 9)
            {

                l4->val = (l1->val + l2->val)% 10;
                l4->next = n;
                l4 = l4->next;
                if(l1->next != NULL)
                {
                    (l1->next->val)++;
                }
                else if(l2->next != NULL)
                {
                    (l2->next->val)++;
                }
                else
                     {l4->val = 1;
                     l4->next = NULL;}
                l1 = l1->next;
                l2 = l2->next;

                if(l2 ==NULL)
                {
                    while(l1 != NULL)
                    {
                       /* l4->next = n;
                        l4 = l4->next;*/
                        if(l1->val >9 )
                        {
                            if(l1->next != NULL)
                            (l1->next->val)++;
                            else
                           { ListNode *new1 = new ListNode;
                             new1->val = 1;
                             new1 ->next = NULL;
                             l1->next = new1;}
                            l4->val = l1->val%10;
                        }
                        else
                        {

                            l4->val = l1->val;
                        }
                        if(l1->next != NULL)
                        {ListNode *n1 = new ListNode;
                        n1->val = 0;
                        n1->next = NULL;
                        l4->next = n1;
                        l4 = l4->next;}
                        l1 = l1->next;

                    }
                }
                else if(l1 ==NULL)
                {
                    while(l2 != NULL)
                    {
                       /* l4->next = n;
                        l4 = l4->next;*/
                        if(l2->val >9 )
                        {
                            if(l2->next != NULL)
                            (l2->next->val)++;
                            else
                           { ListNode *new1 = new ListNode;
                             new1->val = 1;
                             new1 ->next = NULL;
                             l2->next = new1;}
                            l4->val = l2->val%10;
                        }
                        else
                        {

                            l4->val = l2->val;
                        }
                        if(l2->next!=NULL)
                       {ListNode *n1 = new ListNode;
                        n1->val = 0;
                        n1->next = NULL;
                        l4->next = n1;
                        l4 = l4->next;}
                        l2 = l2->next;

                    }
                }

            }
            else
            {
                l4->val = l1->val + l2->val;


                l1 = l1->next;
                l2 = l2->next;

                if(l1 != NULL && l2 != NULL)
                {l4->next = n;
                l4 = l4->next;}
                else if(l1 !=NULL)
                {
                    while(l1 != NULL)
                    {
                        ListNode *n1 = new ListNode;
                        n1->next = NULL;
                        l4->next = n1;
                        l4 = l4->next;
                        l4->val = l1->val;
                        l1 = l1->next;
                    }
                }
                else
                {
                     while(l2 != NULL)
                    {
                        ListNode *n1 = new ListNode;
                        n1->next = NULL;
                        l4->next = n1;
                        l4 = l4->next;
                        l4->val = l2->val;
                        l2= l2->next;
                    }
                }
            }
        }
        return l3;
    }
};
