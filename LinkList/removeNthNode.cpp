// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        unordered_map<int, ListNode*> mapOnNode;
        int i = 1;
        ListNode* curr = head;
        mapOnNode[i] = curr;
        while (curr->next != nullptr) {
            ++i;
            curr = curr->next;
            mapOnNode[i] = curr;
        }
        // remove nth node from the end
        if (i == 1) {
            delete mapOnNode[1];
            head = nullptr;
        }
        else if (i == 2) {
            delete mapOnNode[i - n + 1];
            if (n == 2) {
                head = mapOnNode[i - n + 2];
            }
            else {
                mapOnNode[i - n]->next = nullptr;
            }
        }
        else {
            if (i - n + 1 > 1)
                mapOnNode[i - n]->next = mapOnNode[i - n + 2];
            else {
                head = mapOnNode[i - n + 2];
            }
            delete mapOnNode[i - n + 1];
        }
        return head;
    }
};

int main() {
    return 0;
}