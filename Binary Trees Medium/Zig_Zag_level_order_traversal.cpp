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

vector<vector<int>> zigzagLevelOrder(Node* root) {
	vector<vector<int>> ans;
	if (root == NULL)return ans;

	// we will need a queue ds for level order traversing.
	queue<Node*>q;

	// push the root node
	q.push(root);

	// alternate
	int a = 0;

	// q will contain the root nodes for the next level during every iteration.
	while (!q.empty()) {
		// no. of root nodes on the current level
		int size = q.size();

		// data on current level
		vector<int>level;

		for (int i = 0; i < size; i++) {
			// store the root node in a temporary node and pop it from the queue.
			Node* curr = q.front();
			q.pop();

			// if left node or the right node is not NULL, store them in the queue.
			if (curr->left != NULL)q.push(curr->left);
			if (curr->right)q.push(curr->right);
			level.push_back(curr->data);
		}


		if (a % 2 ==  0) {
			ans.push_back(level);
		}
		else {
			reverse(level.begin(), level.end());
			ans.push_back(level);
		}
		a++;
	}


	return ans;
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