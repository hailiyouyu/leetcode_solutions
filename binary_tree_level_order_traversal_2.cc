class Solution {
    public vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while (!nodes.emtpy()) {
            int n = nodes.size();
            vector<int> level;
            for (int i = 0; i < n; ++i) {
                TreeNode *node = nodes.front();
                nodes.pop();
                level.push_back(node->val);
                if (node->left) {
                    nodes.push(node->left);
                }
                if (node->right) {
                    nodes.push(node->right);
                }
            }
            res.push(level);
        }
    }
    reverse(res.begin(), res.end());
    return res;
};
