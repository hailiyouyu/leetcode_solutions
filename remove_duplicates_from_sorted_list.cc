class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next)
      return head;
    ListNode* p = head, *next;
    while (p) {
      next = p->next;
      if (next && p->val == next->val) {
        p->next = next->next;
        delete next;
      } else {
        p = p->next;
      }
    }
    return head;
  }
};
