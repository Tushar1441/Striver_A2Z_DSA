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


bool isLeaf(Node* root) {
	if (!root->left && !root->right)return true;
	return false;
}

void insertLeftBoundary(Node* root, vector<int>&res) {
	Node* temp = root->left;
	while (temp) {
		// if temp is a leaf node then just ignore it.
		if (!isLeaf(temp))res.push_back(temp->data);
		if (temp->left)temp = temp->left;
		else temp = temp->right;
	}
}

// We can use preorder traversal to insert leaf nodes.
void insertLeafNodes(Node* root, vector<int>&res) {
	if (isLeaf(root)) {
		res.push_back(root->data);
		return;
	}

	if (root->left) insertLeafNodes(root->left, res);
	if (root->right) insertLeafNodes(root->right, res);
}


void insertRightBoundary(Node* root, vector<int>&res) {
	vector<int>temp;

	Node* temp = root->right;
	while (temp) {
		if (!isLeaf(temp))temp.push_back(temp->data);
		if (temp->right)temp = temp->right;
		else temp = temp->left;
	}

	for (int i = temp.size() - 1; i >= 0; i--) {
		res.push_back(temp[i]);
	}
}

vector<int> traverseBoundary(Node* root) {
	vector<int>res;
	if (!root)return res;

	if (!isLeaf(root))res.push_back(root->data);
	insertLeftBoundary(root, res);
	insertLeafNodes(root, res);
	insertRightBoundary(root, res);

	return res;
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
	node1->left->left = new Node(8);
	node1->left->right = new Node(9);
	node1->right->left = new Node(10);
	node1->right->right = new Node(11);

	zigzagLevelOrder(node1);
}