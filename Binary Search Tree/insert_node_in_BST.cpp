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


Node* insertIntoBST(Node* root, int x) {
	if (!root) return new Node(x);
	Node* temp = root;

	while (true) {

		if (temp->data <= x) {

			if (temp->right)temp = temp->right;
			// if a NULL node is found insert the given node.
			else {
				temp->right = new Node(x);
				break;
			}
		}

		else {

			if (temp->left)temp = temp->left;
			else {
				temp->left = new Node(x);
				break;
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