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
