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
    ListNode* oddEvenList(ListNode* head) {

        ListNode* sec = nullptr;
        ListNode* fir = head;
        if(head!=nullptr)
            sec = head->next;

        while (head != nullptr) {
            ListNode* nex = head->next;
            if (nex != nullptr && nex->next != nullptr)
                head->next = nex->next;
            else if(nex!=nullptr)
                head->next =nullptr;
            if (nex == nullptr)
                head = sec;

            head = nex;
        }
        head = fir;
        while (head != nullptr && head->next != nullptr)
            head = head->next;
        if(head)
            head->next = sec;
        return fir;

    }
};