#include<iostream>
#include<vector>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int value;
	TreeNode(int i) : value(i) {}
};

vector<TreeNode*> generateTrees(int n) {
	if (!n) return vector<TreeNode*>();
	return dfs(1, n);
}

vector<TreeNode*> dfs(int l, int r) {
	vector<TreeNode*> ans;
	if (l > r) {
		ans.push_back(nullptr);
		return ans;
	}
	for (int i = l; i <= r; i++) {
		vector<TreeNode*> left = dfs(l, i - 1), right = dfs(i + 1, r);
		for(auto &lc: left)
			for (auto& rc : right) {
				TreeNode* root = new TreeNode(i);
				root->left = lc;
				root->right = rc;
				ans.push_back(root);
			}
	}
	return ans;

}



int main() {


}