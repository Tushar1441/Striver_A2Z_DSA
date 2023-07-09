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

// pass the diameter value by reference and
// calculate the max diameter as max value of (left subtree,rigth subtree) for any root node.
int height(Node* root, int &diameter) {
	if (root == NULL)return 0;

	int lh = height(root->left, diameter);
	int rh = height(root->right, diameter);

	diameter = max(diameter, lh + rh);

	return 1 + max(lh, rh);
}


int diameterOfBinaryTree(Node* root) {
	int diameter = 0;
	height(root, diameter);
	return diameter;
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