class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        int left_height = height(root->left);
        int right_height = height(root->right);
        int diff = left_height - right_height;

        if (diff >= -1 && diff <= 1 && isBalanced(root->left) && isBalanced(root->right))
            return true;
        return false;
    }

    int height(TreeNode *root) {
        if (!root)
            return 0;
        else
            return max(height(root->left), height(root->right)) + 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        int depth = 0;
        return isBalanced(root, depth);
    }
    bool isBalanced(TreeNode *root, int &depth) {
        if (!root) {
            depth = 0;
            return true;
        }
        int left_depth = 0;
        int right_depth = 0;
        if (!isBalanced(root->left, left_depth) || !isBalanced(root->right, right_depth))
            return false;
        
        int diff = left_depth - right_depth;
        if (diff < -1 && diff > 1)
            return false;
        depth = max(left_depth, right_depth) + 1;
        return true;
    }
};
