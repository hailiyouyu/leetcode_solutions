class Solution {
public:
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next)
      return head;
    ListNode* pre, *cur, *next;
    pre = nullptr;
    cur = head;
    while (cur) {
      next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }
};
