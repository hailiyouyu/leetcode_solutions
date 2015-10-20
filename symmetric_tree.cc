class Solution {
public:
  bool isSymmetric(TreeNode *root) {
    if (!root)
      return true;
    queue<TreeNode *> nodes;
    nodes.push(root);

    while (!nodes.empty()) {
      int n = nodes.size();
      vector<TreeNode *> level;
      for (int i = 0; i != n; ++i) {
        TreeNode *node = nodes.front();
        nodes.pop();
        level.push_back(node);

        if (node) {
          nodes.push(node->left);
          nodes.push(node->right);
        }
      }
      for (int i = 0; i != n/2; ++i) {
        if (level[i] == NULL && level[n-i-1] == NULL)
          continue;
        if (level[i] == NULL || level[n-i-1] == NULL)
          return false;
        if (level[i]->val != level[n-i-1]->val)
          return false;
      }
    }
    return true;
  }
};

class Solution2 {
public:
  bool isSymmetric(TreeNode *root) {
    return root ? helper(root->left, root->right) : true;
  }
  bool helper(TreeNode *left, TreeNode *right) {
    if (!left && !right)
      return true;
    if (!left || !right)
      return false;
    if (left->val != right->val)
      return false;
    return helper(left->left, right->right) && helper(left->right, right->left);
  }
};
