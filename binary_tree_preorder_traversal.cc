class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
	vector<int> data;
	if (!root)
	    return data;
	stack<TreeNode *> nodes;
	nodes.push(root);

	while (!nodes.empty()) {
	    TreeNode *pNode = nodes.top();
	    nodes.pop();

	    data.push_back(pNode->val);

	    if (pNode->right)
		nodes.push(pNode->right);
	    if (pNode->left)
		nodes.push(pNode->left);
	}
	return data;
    }
};
