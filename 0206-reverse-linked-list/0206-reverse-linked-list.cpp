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
    ListNode* reverseList(ListNode* head) {
        ListNode* currnode = head;
        ListNode* nextnode = head;
        ListNode* prevnode = 0;
        while(nextnode!=nullptr){
            nextnode = currnode->next;
            currnode->next = prevnode;
            prevnode= currnode;
            currnode = nextnode;
        }
        head = prevnode;
        return head;
    }
};