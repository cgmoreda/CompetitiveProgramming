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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while (node)
            n++, node = node->next;
        if(n==1)
        {
            return nullptr;
        }
        node = head;
        n /= 2;
        while (node) {
            n--;
            if (n == 0) {
                node->next = node->next->next;
                break;
            }
            node = node->next;
        }
        return head;
    }
};