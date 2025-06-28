class Solution {
	vector<TreeNode *> generateFBTs(int n) {
		if(n == 1) return {new TreeNode(0)};
		vector<TreeNode *> trees;
		n--; 
		
		vector<TreeNode *> leftChoices, rightChoices;
		for(int i = 1; i<n; i+=2) {
			leftChoices = generateFBTs(i);
			rightChoices = generateFBTs(n-i);
			for(TreeNode *j : leftChoices) {
				for(TreeNode *k : rightChoices) {
					TreeNode *root = new TreeNode(0);
					root->left = j;
					root->right = k;
					trees.push_back(root);
				}
			}
		}
		return trees;
	}
public: 
	vector<TreeNode *> allPossibleFBT(int n) {
		if(n == 1) return {new TreeNode(0)};
		else if(n%2 == 0) return {};
		else if(n==3) return {new TreeNode(0, new TreeNode(0), new TreeNode(0))};
		return generateFBTs(n);
	}
};
