class Solution {
public:
  bool isValidBST(TreeNode *root) {
    if (!root)
      return true;
    bool b1, b2;
    b1 = b2 = true;
    if (root->left)
      b1 = root->left->val < root->val;
    if (root->right)
      b2 = root->right->val > root->val;
    return b1 && b2 && isValidBST(root->left) && isValidBST(root->right);
  }
};
