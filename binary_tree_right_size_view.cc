class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> data;
        if (!root)
            return data;
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int n = nodes.size();
            for (int i = 0; i < n; ++i) {
                TreeNode *node = nodes.front();
                nodes.pop();

                if (i == n-1)
                    data.push_back(node->val);
                if (node->left)
                    nodes.push(node->left);
                if (node->right)
                    nodes.push(node->right);
            }
        }
        return data;
    }
};
