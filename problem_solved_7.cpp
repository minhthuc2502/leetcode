/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void push(ListNode ** list, int newdata)
{
    ListNode * node = new ListNode();
    ListNode * last = *list; 
    node->val = newdata;
    node->next = NULL;
    if(*list == NULL)
    {
        *list = node;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = node;
}
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode *lend = NULL;
            if(l1 == NULL)
            {
                while(l2!=NULL)
                {
                    push(&lend, l2->val);
                    l2 = l2->next;
                }
            }
            else if(l2 == NULL)
            {
                while(l1!=NULL)
                {
                    push(&lend, l1->val);
                    l1 = l1->next;
                }
            }
            else if (l2 == NULL)
            {
                push(&lend, l1->val);
                return lend;
            }
            while(l1 != NULL && l2 != NULL)
            {
                if(l1->val <= l2->val)
                {
                    push(&lend, l1->val);
                    l1 = l1->next;
                }
                else if (l1->val > l2->val)
                {
                    push(&lend, l2->val);
                    l2 = l2->next;
                }
            }
            if(l1 == NULL)
            {
                while(l2!=NULL)
                {
                    push(&lend, l2->val);
                    l2 = l2->next;
                }
            }
            else if(l2 == NULL)
            {
                while(l1!=NULL)
                {
                    push(&lend, l1->val);
                    l1 = l1->next;
                }
            }
            return lend;
        }
};
