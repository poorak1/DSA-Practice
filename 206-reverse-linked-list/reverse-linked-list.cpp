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
        ListNode *tmp = nullptr;
        ListNode *ptr2 = head;
    
        while(ptr2){
            ptr2 = ptr2 -> next; 
            head->next = tmp;
            tmp = head;
            head = ptr2; 
        }
        return tmp;
    }
};