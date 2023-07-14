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


Node* findLastRight(Node* root) {
	while (root->right) {
		root = root->right;
	}
	return root;
}

Node* helper(Node* root) {

	// if the node to be deleted has one child as NULL then connect its parent node to
	// the other child.
	if (root->left == NULL) {
		return root->right;
	}
	else if (root->right == NULL) {
		return root->left;
	}


	// store the right subtree node and disconnect it from the tree.
	Node* rightChild = root->right;

	// find the extreme right node for the left child and connect the previously
	// dizconnected subtree to it.
	Node* lastRight = findLastRight(root->left);
	lastRight->right = rightChild;

	return root->left;
}

Node* deleteNode(Node* root, int x) {
	if (root == NULL)return root;

	if (root->data == x) {
		return helper(root);
	}

	Node* temp = root;

	while (temp) {
		if (temp->data > x) {
			if (temp->left != NULL && temp->left->data == x) {
				temp->left = helper(temp->left);
				break;
			}

			else {
				temp = temp->left;
			}
		}

		else {
			if (temp->right != NULL && temp->right->data == x) {
				temp->right = helper(temp->right);
				break;
			}
			else {
				temp = temp->right;
			}
		}
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