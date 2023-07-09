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


int findHeight(Node* root) {
	// base case
	if (root == NULL)return 0;

	int lh = findHeight(root->left);
	int rh = findHeight(root->right);

	return 1 + max(lh, rh);
}


// Brute Force Aproach
// At every node find out the height of the left subtree and the right subtree.
bool isBalanced1(Node* root) {
	if (root == NULL)return 1;

	int lh = findHeight(root->left);
	int rh = findHeight(root->right);

	if (abs(lh - rh) > 1)return false;

	bool left = isBalanced1(root->left);
	bool right = isBalanced1(root->right);

	return (!left || !right)return false;

	return true;
}


// using a recurrence relation -->
// height of Binary Tree =  1 + max(left tree height, right tree height)
int dfsHeight(Node* root) {
	// base case
	if (root == NULL)return 0;

	int lh = dfsHeight(root->left);
	if (lh == -1)return -1;

	int rh = dfsHeight(root->right);
	if (rh == -1)return -1;


	if (abs(lh - rh) > 1)return -1;
	return 1 + max(lh, rh);
}

bool isBalanced(Node* root) {
	return dfsHeight(root) != -1 ;
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