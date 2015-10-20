class Solution {
public:
  int sumNumbers(TreeNode *root) {
    vector<int> sum;
    findPath(root, sum);
    return accumulate(sum.begin(), sum.end(), 0);
  }

  void findPath(TreeNode *root, vector<int> &sum) {
    stack<pair<TreeNode *, bool>> nodes;
    vector<int> path;

    while (root || !nodes.empty()) {
      if (root) {
        nodes.push(make_pair(root, true));
        path.push_back(root->val);
        root = root->left;
      } else {
        pair<TreeNode *, bool> node = nodes.top();
        nodes.pop();

        if (node.second) {
          node.second = false;
          nodes.push(node);
          root = node.first->right;
        } else {
          if (!node.first->left && !node.first->right) {
            int s = 0;
            for (int i = 0; i != path.size(); ++i) {
              s = 10 * s + path[i];
            }
            sum.push_back(s);
          }
          path.pop_back();
          root = NULL;
        }
      }
    }
  }
};
