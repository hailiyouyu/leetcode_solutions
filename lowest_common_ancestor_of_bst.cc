class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q)
      return NULL;
    if (p->val < root->val && q->val < root->val)
      return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val)
      return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};

class Solution2 {
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || !p || !q)
      return NULL;
    TreeNode *node = root;
    while (node) {
      if (p->val < node->val && q->val < node->val)
        node = node->left;
      else if (p->val > node->val && q->val > node->val)
        node = node->right;
      else
        return node;
    }
    return NULL;
  }
};
