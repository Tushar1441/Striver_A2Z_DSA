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



// Recursive Way
// check if the left subtree is mirror image of the right subtree using preorder traversal
// for mirror image, remember that-
// in the left subtree we check in the order of [root->left->right]
// in the right subtree it should be equal to in order of [root->right->left]
bool check(Node* curr1, Node*  curr2) {
	if (curr1 == NULL || curr2 == NULL) {
		return curr1 == curr2;
	}

	if (curr1->val != curr2->val)return false;

	return check(curr1->left, curr2->right) && check(curr1->right, curr2->left);
}

bool isSymmetric(Node* root) {
	return (root == NULL || check(root->left, root->right));
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