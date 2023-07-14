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


Node* helper(Node* curr, int val) {
	if (!curr || curr->data == val) {
		return curr;
	}

	if (val > curr->data)return helper(curr->right, val);
	else return helper(curr->left, val);
}


// Recursive version
Node* searchBST(Node* root, int val) {
	return helper(root, val);
}


// Iterative Version
Node* searchBST1(Node* root, int val) {
	while (root != NULL && root->data != val) {
		root = root->data > val ? root->left : root->right;
	}

	return root;
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