class Solution {
public:
  void deleteNode(ListNode* node) {
    if (!node)
      return;
    ListNode* p = node->next;
    if (!p) {
      delete node;
      node = nullptr;
    } else {
      node->val = p->val;
      node->next = p->next;
      delete p;
    }
  }
};
