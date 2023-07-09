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



vector<vector<int>> verticalTraversal(Node* root) {
	vector<vector<int>>res;
	if (!root)return res;

	// we need level wise sorted elements with resective verticals
	// there can be duplicate elements in a level, so will need a multiset.
	map < int, map< int, multiset<int>>>nodes;

	// for traversal, we can use a queue data structure.
	// it store the node and its respective vertces(x,y).
	queue < pair<Node*, pair<int, int>>>q;
	// root is the vertex
	q.push({root, {0, 0}});

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		Node* temp = it.first;
		// x is the column, y is the level
		int x = it.second.first, y = it.second.second;

		// insert the node in the map ds
		nodes[x][y].insert(temp->data);

		// insert the left and the right nodes in the queue
		// if we go left, the col reduce.
		if (temp->left) {
			q.push({temp->left, {x - 1, y + 1}});
		}

		// if we go right, the col incerease
		if (temp->right) {
			q.push({temp->right, {x + 1, y + 1}});
		}
	}

	// now fill the map nodes into vector
	for (auto it : nodes) {
		vector<int>col;
		for (auto p : it.second) {
			col.insert(col.end(), p.second.begin(), p.second.end());
		}
		res.push_back(col);
	}


	return res;
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