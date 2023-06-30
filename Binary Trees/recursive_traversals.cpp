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


void preOrder(Node* root) {
	if (root == NULL)return;

	cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
}
void postOrder(Node* root) {
	if (root == NULL)return;

	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}
void inOrder(Node* root) {
	if (root == NULL)return;

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
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
	preOrder(node1); cout << endl;
	postOrder(node1); cout << endl;
	inOrder(node1); cout << endl;
}