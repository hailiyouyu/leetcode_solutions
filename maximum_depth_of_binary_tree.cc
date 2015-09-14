class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        else
            return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/* non-recursively */
class Solution2 {
public:
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        stack<pair<TreeNode *, bool>> nodes;
        int depth = 0;

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
                    if (!node.first->left && !node.first->right) {
                        int tempDepth = nodes.size() + 1;
                        depth = max(depth, tempDepth);
                    }
                    root = nullptr;
                }
            }
        }
        return depth;
    }
};

/* BFS-solution */
class Solution3 {
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;
        queue<TreeNode *> nodes;
        int depth = 0;
        
        nodes.push(root);
        while (!nodes.empty()) {
            depth += 1;

            for (int i = 0; i < nodes.size(); ++i) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (!node->left) {
                    nodes.push(node->left);
                }
                if (!node->right) {
                    nodes.push(node->right);
                }
            }
        }
        return depth;
    }
};
