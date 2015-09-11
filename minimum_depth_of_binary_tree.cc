class Solution {
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        stack<pair<TreeNode *, bool>> nodes;
        int depth = INT_MAX;
        
        while (root || !nodes.empty()) {
            if (root) {
                nodes.push(make_pair(root, true));
                root = root->left;
            } else {
                pair<TreeNode *, bool> node = nodes.top();
                nodes.pop();

                if (node.second) {
                    node.second = false;
                    nodes.push(node);
                    root = node.first->right;
                } else {
                    if (!node.first->left && !node.first->second) {
                        int tempDepth = nodes.size() + 1;
                        depth = min(depth, tempDepth);
                    }
                    root = nullptr;
                }
            }
        }
        return depth;
    }
};
