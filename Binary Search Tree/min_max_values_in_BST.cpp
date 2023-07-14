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


// Iterative Version
// For minimum go to the extreme left possible
int minValue(Node* root) {
	if (!root)return -1;

	while (!root->left) {
		root = root->left;
	}

	return root->data;
}

// For maximum go to the extreme right possible
int maxValue(Node* root) {
	if (!root)return -1;

	while (!root->right) {
		root = root->right;
	}

	return root->data;
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