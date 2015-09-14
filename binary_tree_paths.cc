class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        vector<int> path;
        findPaths(root, res, path);
        return res;
    }
    void findPaths(TreeNode *root, vector<string> &res, vector<int> &path) {
        if (!root)
            return;

        path.push_back(root->val);
        if (!root->left && !root->right) {
            string s;
            for (int i = 0; i < path.size()-1; ++i)
                s += to_string(path[i]) + "->";
            s += to_string(path[path.size()-1]);
            res.push_back(s);
        }
        if (root->left)
            findPaths(root->left, res, path);
        if (root->right)
            findPaths(root->right, res, path);
        path.pop_back();
    }
};
