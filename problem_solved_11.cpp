/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0;
        bool sup = false;
        ListNode* tmp1 = l1;
        ListNode* tmp2 = l2;
        ListNode* listresult = NULL;
        while(tmp1 != NULL || tmp2 != NULL)
        {
            if(tmp1 != NULL && tmp2 != NULL)
            {
                if(sup == true)
                {
                    val = tmp1->val + tmp2->val + 1;
                    sup = false;
                }
                else
                    val = tmp1->val + tmp2->val;
                if(val >= 10)
                {
                    val = val - 10;
                    sup = true;
                }
                push(&listresult,val);
            }
            else if(tmp1 != NULL)
            {
                if(sup == true)
                {
                    val = tmp1->val +1;
                    sup = false;
                }
                else 
                    val = tmp1->val;
                if(val >= 10)
                {
                    val = val - 10;
                    sup = true;
                }
                push(&listresult,val);
            }
            else if(tmp2 != NULL)
            {
                if(sup == true)
                {
                    val = tmp2->val +1;
                    sup = false;
                }
                else 
                    val = tmp2->val;
                if(val >= 10)
                {
                    val = val - 10;
                    sup = true;
                }
                push(&listresult,val);
            }
            if(tmp1 != NULL)
                tmp1 = tmp1->next;
            if(tmp2 != NULL)
                tmp2 = tmp2->next;
        }
        if(sup == true)
            push(&listresult,1);
        return listresult;
    }
};

/****************************
 * another methode
 * Limit: can't use for a list node long
 * **************************/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        unsigned long long vall1 = 0, vall2 = 0;
        unsigned long long val = 0;
        int i = 0;
        ListNode* tmp = l1;
        ListNode* listresult = NULL;
        while(tmp->next != NULL)
        {
            vall1 += tmp->val * pow(10,i);
            i++;
            tmp = tmp->next;
        }
        vall1 += tmp->val * pow(10,i);
        i = 0;
        tmp = l2;
        while(tmp->next != NULL)
        {
            vall2 += tmp->val * pow(10,i);
            i++;
            tmp = tmp->next;
        }
        vall2 += tmp->val * pow(10,i);
        val = vall1 + vall2;
        if(val == 0)
        {
            push(&listresult,val);
            return listresult;
        }
        while(val != 0)
        {
            push(&listresult,val % 10);
            val = val / 10;
        }
        return listresult;
    }
};