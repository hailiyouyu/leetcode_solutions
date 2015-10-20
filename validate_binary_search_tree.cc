class Solution {
public:
  bool isValidBST(TreeNode *root) {
    vector<int> data = inorder(root);
    for (int i = 0; i != data.size() - 1; ++i) {
      if (data[i] >= data[i+1])
        return false;
    }
    return true;
  }

  vector<int> inorder(TreeNode *root) {
    vector<int> data;
    stack<TreeNode *> nodes;

    while (root || !nodes.empty()) {
      if (root) {
        nodes.push(root);
        root = root->left;
      } else {
        TreeNode *node = nodes.top();
        nodes.pop();

        data.push_back(node->val);
        root = node->right;
      }
    }
    return data;
  }
};
