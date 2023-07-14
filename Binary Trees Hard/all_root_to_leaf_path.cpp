#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int val) {
		this->data = val;
		this->left = this->right = NULL;
	}
};


void getpaths(Node* root, vector<string>&ans, string res) {
	if (!root) {
		return;
	}

	res += to_string(root->data) + "->";

	// if a leaf node is found
	if (root->left == NULL && root->right == NULL) {
		// pop the arrow in two iterations.
		res.pop_back();
		res.pop_back();
		// and then push the string.
		ans.push_back(res);
	}

	// call the left guy and then the right guy.
	getpaths(root->left, ans, res);
	getpaths(root->right, ans, res);

	// at last remove
	res.pop_back();
}


// We can use inorder traversal to store all the node to leaf paths.
vector<string> allRootToLeaf(Node* root) {
	vector<string>ans;
	if (!root) return ans;

	string res = "";
	getpaths(root, ans, res);
	return ans;

}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
#endif

	Node* node1 = new Node(5);
	node1->left = new Node(6);
	node1->right = new Node(7);

}