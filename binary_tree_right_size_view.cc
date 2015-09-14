class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> data;
        if (!root)
            return data;
        while (root) {
            data.push_back(root->val);
            if (root->right)
                root = root->right;
            else if (!root->left)
                break;
            else
                root = root->left;
        }
        return data;
    }
};
