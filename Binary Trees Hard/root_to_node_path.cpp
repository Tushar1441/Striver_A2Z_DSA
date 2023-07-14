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


bool getpaths(Node* root, vector<string>&ans, int b) {
	if (!root) {
		return false;
	}

	ans.push_back(root->data);

	if (root->data == b)return true;

	if (getpaths(root->left, ans, res) || getpaths(root->right, ans, res)) return true;

	ans.pop_back();
	return false;
}


// We can use inorder traversal to store all the node to leaf paths.
vector<string> allRootToLeaf(Node* root , int b) {
	vector<string>ans;
	if (!root) return ans;

	string res = "";
	getpaths(root, ans, b);
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