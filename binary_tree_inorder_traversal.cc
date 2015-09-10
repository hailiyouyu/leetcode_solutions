class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
	vector<int> data;
	stack<TreeNode *> nodes;

	while (root || !nodes.empty()) {
	    if (root) {
		nodes.push(root);
		root = root->left;
	    } else {
		TreeNode *node = nodes.top();
		nodes.pop();
		data.push_back(node->val);
		root = node->right;
	    }
	}
	return data;
    }
};
