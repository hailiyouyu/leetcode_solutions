class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> data;
        if (!root)
            return data;
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            vector<int> temp;
            for (int i = 0; i < nodes.size(); ++i) {
                TreeNode *node = nodes.front();
                nodes.pop();
                temp.push_back(node->val);
                if (!node->left)
                    nodes.push(node->left);
                if (!node->right)
                    nodes.push(node->right);
            }
            data.push_back(temp);
        }
        return data;
    }
};
