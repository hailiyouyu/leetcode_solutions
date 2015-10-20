class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->right = left;
    root->left = right;
    return root;
  }
};
