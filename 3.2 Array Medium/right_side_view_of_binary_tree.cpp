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



// Iterative Way --> Using Level Order Traversal
// To get the right view, we need levels which are already arranged in sorted order.
// so we don't need a map ds to store them like we did in top and bottom view.
vector<int> rightSideView(Node* root) {
	vector<int>ans;
	if (!root)return ans;

	// declare a queue ds with node and its level
	queue<pair<Node*, int>>q;

	// push the root node with level 0.
	q.push({root, 0});

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		Node* temp = it.first;
		int level = it.second;

		// store/update the value in the res
		if (res.size() <= level) res.push_back(temp->data);
		else res[level] = temp->data;

		// check for left and right nodes.
		if (temp->left) {
			q.push({temp->left, level + 1});
		}
		if (temp->right) {
			q.push({temp->right, level + 1});
		}
	}

	return res;
}


// Recursive Solution --> It is short and more clear and crisp.
void solveRight(Node* root, vector<int>&ds, int level) {
	if (root == NULL)return;

	if (ds.size == level)ds.push_back(root->data);

	// first move to the right node, so that we store the right view first.
	// if we want to store the left view, then we just have to change the order of the traversal
	solve(root->right, ds, level + 1);
	solve(root->left, ds, level + 1);
}

vector<int> rightSideView1(Node* root) {
	vector<int>ds;
	if (!root)return ds;

	solveRight(root, ds, 0);
	return ds;
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