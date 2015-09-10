class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
	vector<int> data;
	if (!root)
	    return data;

	stack<TreeNode *> tempNodes;
	stack<TreeNode *> nodes;
	TreeNode *pNode;

	tempNodes.push(root);
	while (!tempNodes.empty()) {
	    pNode = tempNodes.top();
	    tempNodes.pop();

	    nodes.push(pNode);
	    if (pNode->left)
		tempNodes.push(pNode->left);
	    if (pNode->right)
		tempNodes.push(pNode->right);
	}
	while (!nodes.empty()) {
	    pNode = nodes.top();
	    nodes.pop();
	    data.push_back(pNode->val);
	}
	return data;
    }
};
