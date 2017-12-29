/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
 * Time complexity: O(max(m, n))
 * Space complexity: O(max(m, n))
 * */
class Solution {
  public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode* h,
       ListNode* s = new ListNode(0);
       ListNode* p1 = l1;
       ListNode* p2 = l2;

       h = s;
       while (true) {
         if (p1 != NULL) {
           h->val += p1->val;
         }
         if (p2 != NULL) {
           h->val += p2->val;
         }

         if (p1 != NULL) p1 = p1->next;
         if (p2 != NULL) p2 = p2->next;

         if (h->val >= 10) {
           h->next = new ListNode(1);
           h->val -= 10;
           h = h->next;
         } else if (p1 == NULL && p2 == NULL) {
           break;
         } else {
           h->next = new ListNode(0);
           h = h->next;
         }
       }

       return s;
     }
};
