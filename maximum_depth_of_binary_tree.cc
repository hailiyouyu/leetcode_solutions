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
                    if (!node.first->left && !node.first->right)
                        depth = max(depth, nodes.size()+1);
                    root = nullptr;
                }
            }
        }
    }
};
