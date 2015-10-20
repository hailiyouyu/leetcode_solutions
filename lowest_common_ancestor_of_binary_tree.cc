class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> pathP = findPath(root, p);
    vector<TreeNode *> pathQ = findPath(root, q);

    int i;
    for (i = 0; i < pathP.size() && i < pathQ.size(); ++i) {
      if (pathP[i] != pathQ[i])
        break;
    }
    return i > 0 ? pathP[i-1] : NULL;
  }
  vector<TreeNode *> findPath(TreeNode *root, TreeNode *node) {
    vector<TreeNode *> path;
    stack<pair<TreeNode *, bool>> nodes;

    while (root || !nodes.empty()) {
      if (root) {
        nodes.push(make_pair(root, true));
        path.push_back(root);
        root = root->left;
      } else {
        pair<TreeNode *, bool> cur = nodes.top();
        nodes.pop();

        if (cur.second) {
          cur.second = false;
          nodes.push(cur);
          root = cur.first->right;
        } else {
          if (cur.first == node)
            break;
          root = NULL;
          path.pop_back();
        }
      }
    }
    return path;
  }
};
