class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> res;
    vector<int> path;
    findPathHelper(root, res, path, sum);
    return res;
  }
  void findPathHelper(TreeNode *root, vector<vector<int>> &res, vector<int> &curPath, int curSum) {
    if (!root)
      return;
    if (root->val > curSum)
      return;
    if (!root->left && !root->right) {
      if (root->val == curSum) {
        curPath.push_back(root->val);
        res.push_back(curPath);
        curPath.pop_back();
        return;
      } else {
        return;
      }
    }
    curPath.push_back(root->value);
    if (root->left)
      findPathHelper(root->left, res, curPath, curSum-root->value);
    if (root->right)
      findPathHelper(root->right, res, curPath, curSum-root->value);
    curPath.pop_back();
  }
};
