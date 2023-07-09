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

// using a recurrence relation -->
// height of Binary Tree =  1 + max(left tree height, right tree height)
int maxDepth(Node* root) {
	// base case
	if (root == NULL)return 0;

	int lh = maxDepth(root->left);
	int rh = maxDepth(root->right);

	return 1 + max(lh, rh);
}


// using level order Traversal
int maxDepth1(Node* root) {
	if (root == NULL)return 0;

	// answer
	int depth = 0;

	// we will need a queue ds for level order traversing.
	queue<Node*>q;
	q.push(root);

	// q will contain the root nodes for the next level during every iteration.
	while (!q.empty()) {
		// no. of root nodes on the current level
		int size = q.size();

		for (int i = 0; i < size; i++) {
			// store the root node in a temporary node and pop it from the queue.
			Node* curr = q.front();
			q.pop();

			// if left node or the right node is not NULL, store them in the queue.
			if (curr->left != NULL)q.push(curr->left);
			if (curr->right)q.push(curr->right);

		}

		depth++;
	}

	return depth;
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