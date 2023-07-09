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


// It is very similar to top view.
// The only change is that we will upadte the col node data
// in the map everytime we visit a previously visited col.
vector<int> getBottomView(Node* root) {
	vector<int>res;
	if (!root)return res;

	// declare a queue ds with node and its column number
	queue<pair<Node*, int>>q;

	q.push({root, 0});

	// declare a map ds to store the value and its column.
	map<int, int>bottoms;

	while (!q.empty()) {
		auto it = q.front();
		q.pop();

		Node* temp = it.first;
		int col = it.second;
		// put the node data into map
		bottoms[col] = temp->data;

		if (temp->left) {
			q.push({temp->left, col - 1});
		}
		if (temp->right) {
			q.push({temp->right, col + 1});
		}
	}

	for (auto it : bottoms) {
		res.push_back(it.second);
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